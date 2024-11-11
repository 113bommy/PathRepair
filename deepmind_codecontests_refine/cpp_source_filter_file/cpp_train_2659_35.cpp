#include <bits/stdc++.h>
using namespace std;
int qq, n, m, k, l, r;
string s, s1;
int INF = (int)1e9 + 7;
struct st {
  long long mi, ma, mir, mar, mir2, mar2;
};
vector<st> v;
multimap<int, st> ma;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ans = 0;
  int t, x = 1, y = n, k1, k2, k3, x1, x2;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> m;
    k1++;
    if (m > k) k1++;
  }
  cout << k;
  cin >> k;
  return 0;
}
