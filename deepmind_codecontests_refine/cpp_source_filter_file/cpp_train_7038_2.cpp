#include <bits/stdc++.h>
using namespace std;
struct comp {
  bool operator()(long long a, long long b) { return a > b; }
};
long long n, k, a[605][605], t, first[305], second[305], p, q, f, ans;
string s;
map<string, long long> m;
set<long long, comp> fk;
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> p >> q >> k >> f;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (m[s])
      first[i] = m[s];
    else
      m[s] = ++t, first[i] = t;
    cin >> s;
    if (m[s])
      second[i] = m[s];
    else
      m[s] = ++t, second[i] = t;
  }
  for (int i = 1; i <= n; i++) {
    if (first[i] == second[i - 1])
      a[first[i]][second[i]] += q;
    else
      a[first[i]][second[i]] += p;
  }
  for (int i = 1; i <= t; i++) {
    for (int j = i + 1; j <= t; j++) {
      fk.insert(a[i][j] + a[j][i]);
      ans += a[i][j] + a[j][i];
    }
  }
  while (fk.size() && *(fk.begin()) > f && k) {
    ans -= *(fk.begin()) - f;
    fk.erase(fk.begin());
    k--;
  }
  cout << ans;
}
