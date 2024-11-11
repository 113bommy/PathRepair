#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b, long long m) {
  T ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = ((ans % m) * (a % m)) % m;
    b /= 2;
    a = ((a % m) * (a % m)) % m;
  }
  return ans % m;
}
const long double eps = 1e-10L;
int a[500005][6];
set<pair<int, int> > s[6];
int id[6];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  int ans = 0;
  int l = 1;
  int fans = 0;
  for (int r = 1; r <= n; r++) {
    ans = 0;
    for (int j = 1; j <= m; j++) {
      s[j].insert(make_pair(a[r][j], r));
      set<pair<int, int> >::reverse_iterator it = (s[j].rbegin());
      ans += (*it).first;
    }
    while (l <= r && ans > k) {
      ans = 0;
      for (int j = 1; j <= m; j++) {
        s[j].erase(make_pair(a[l][j], l));
        if (s[j].size() > 0) {
          set<pair<int, int> >::reverse_iterator it = (s[j].rbegin());
          ans += (*it).first;
        }
      }
      l++;
    }
    int temp = (r - l + 1);
    if (temp > fans) {
      fans = temp;
      for (int j = 1; j <= m; j++) {
        set<pair<int, int> >::reverse_iterator it = (s[j].rbegin());
        id[j] = (*it).first;
      }
    }
  }
  for (int i = 1; i <= m; i++) cout << id[i] << " ";
}
