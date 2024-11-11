#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
char s[maxn], tmp[maxn];
int sum[maxn];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s + 1);
  int pos = 0, minn = 0, sumx = 0;
  for (int i = 1; i <= n; i++) {
    sumx += s[i] == '(' ? 1 : -1;
    if (sumx < minn) minn = sumx, pos = i;
  }
  if (sumx != 0) {
    cout << 0 << '\n' << 1 << ' ' << 1 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) tmp[i] = s[(pos + i - 1) % n + 1];
  vector<int> Q;
  Q.clear();
  Q.push_back(0);
  int cnt = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    s[i] = tmp[i];
    sum[i] += sum[i - 1] + (s[i] == '(' ? 1 : -1);
    if (!sum[i]) ++cnt, Q.push_back(i);
  }
  ans = cnt;
  int L = 1, R = 1;
  int len = Q.size();
  for (int i = 1; i < len; i++) {
    int l = Q[i - 1] + 1, r = Q[i], t = 0;
    for (int j = l; j <= r; j++) t += (sum[j] == 1);
    if (ans < t) {
      ans = t;
      L = l;
      R = r;
    }
  }
  Q.clear();
  for (int i = 1; i <= n; i++)
    if (sum[i] == 1) Q.push_back(i);
  len = Q.size();
  for (int i = 1; i < len; i++) {
    int l = Q[i - 1] + 1, r = Q[i], t = cnt;
    for (int j = l; j <= r; j++)
      if (!sum[i]) t++;
    if (ans < t) {
      ans = t;
      L = l;
      R = r;
    }
  }
  cout << ans << endl;
  cout << (L + pos - 1) % n + 1 << ' ' << (R + pos - 1) % n + 1 << endl;
  return 0;
}
