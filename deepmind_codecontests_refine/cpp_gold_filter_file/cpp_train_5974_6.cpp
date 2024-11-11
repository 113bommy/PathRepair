#include <bits/stdc++.h>
using namespace std;
const int maxn = 100002;
long long a[maxn], n, k;
vector<int> v;
map<int, int> m, u;
void read() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%I64d", &a[i]);
    m[a[i]] = 1;
  }
}
void solve() {
  if (k == 1) {
    cout << n << endl;
    return;
  }
  sort(a, a + n);
  long long tmp;
  long long ans = 0, br;
  for (int i = 0; i < n; ++i)
    if (!u.count(a[i])) {
      v.clear();
      u[a[i]] = 1;
      tmp = a[i] * k;
      br = 1;
      while (tmp > 0 && tmp <= a[n - 1] && m.count(tmp)) {
        u[tmp] = 1;
        br++;
        tmp *= k;
      }
      ans += br / 2;
      ans += br % 2;
    }
  cout << ans << endl;
}
int main() {
  read();
  solve();
  return 0;
}
