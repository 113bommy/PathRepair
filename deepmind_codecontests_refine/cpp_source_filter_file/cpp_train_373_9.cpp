#include <bits/stdc++.h>
using namespace std;
const int LEN = 300;
int x[100000], t[100000], z[100000];
pair<int, int> y[100000];
long long sum[100000 / LEN + 1][5];
int cnt[100000 / LEN];
int w[100000 / LEN][LEN];
int n, m, o;
char s[10];
long long cal() {
  int cur = 0;
  long long ans = 0;
  for (int i = 0; i < o; i++) {
    ans += ::sum[i][(7 - cur) % 5];
    cur = (cur + ::cnt[i]) % 5;
  }
  return ans;
}
void add(int x, int y) {
  int j = x / LEN;
  for (int i = cnt[j]; i >= 0; i--)
    if (i > 0 && w[j][i - 1] > y)
      w[j][i] = w[j][i - 1];
    else {
      w[j][i] = y;
      break;
    }
  cnt[j]++;
  for (int i = 0; i < 5; i++) sum[j][i] = 0;
  for (int i = 0, k = 0; i < cnt[j]; i++, k = (k == 4 ? 0 : k + 1)) {
    sum[j][k] += w[j][i];
  }
}
void del(int x, int y) {
  int j = x / LEN;
  for (int i = 0; i < cnt[j]; i++)
    if (w[j][i] == y) {
      for (int q = i; q + 1 < cnt[j]; q++) w[j][q] = w[j][q + 1];
      break;
    }
  cnt[j]--;
  for (int i = 0; i < 5; i++) sum[j][i] = 0;
  for (int i = 0, k = 0; i < cnt[j]; i++, k = (k == 4 ? 0 : k + 1)) {
    sum[j][k] += w[j][i];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", &s);
    if (s[0] == 'a')
      t[i] = 0;
    else if (s[0] == 'd')
      t[i] = 1;
    else
      t[i] = 2;
    if (t[i] != 2) scanf("%d", &x[i]);
    y[i] = make_pair(x[i], i);
  }
  sort(y, y + n);
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && y[i - 1].first != y[i].first) r++;
    z[y[i].second] = r;
  }
  o = (n + LEN - 1) / LEN;
  for (int i = 0; i < n; i++) {
    if (t[i] == 2)
      printf("%I64d\n", cal());
    else if (t[i] == 0)
      add(z[i], x[i]);
    else
      del(z[i], x[i]);
  }
  return 0;
}
