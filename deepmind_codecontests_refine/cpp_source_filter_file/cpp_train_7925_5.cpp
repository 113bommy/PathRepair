#include <bits/stdc++.h>
using namespace std;
template <typename T, typename Pr = less<T>>
using pq = priority_queue<T, vector<T>, Pr>;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
int opc = 0;
string a, b;
void op(int k, int x) {
  if (opc == 100000) return;
  if (x > 0) {
    a[k]++;
    if (a[k + 1] == '9') {
      op(k + 1, -1);
      if (opc == 100000) return;
    }
    a[k + 1]++;
    opc++;
    printf("%d %d\n", k + 1, x);
  } else {
    a[k]--;
    if (a[k + 1] == '0') {
      op(k + 1, 1);
      if (opc == 100000) return;
    }
    a[k + 1]--;
    opc++;
    printf("%d %d\n", k + 1, x);
  }
}
int main() {
  int n;
  cin >> n >> a >> b;
  vector<i64> ad, bd;
  for (int i = 0; i < n; i++) {
    ad.push_back(a[i] - '0');
    bd.push_back(b[i] - '0');
  }
  i64 asum = 0, bsum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      asum += 9 - ad[i];
      bsum += 9 - bd[i];
    } else {
      asum += ad[i];
      bsum += bd[i];
    }
  }
  if (asum != bsum) {
    printf("-1\n");
    return 0;
  }
  i64 ans = 0;
  for (int i = 0; i < n - 1; i++) {
    i64 ch = ad[i] - bd[i];
    ans += llabs(ch);
    ad[i + 1] += ch;
  }
  printf("%lld\n", ans);
  for (int i = 0; i < n; i++) {
    while (a[i] < b[i] && opc < 100000) op(i, 1);
    while (a[i] > b[i] && opc < 100000) op(i, -1);
  }
  return 0;
}
