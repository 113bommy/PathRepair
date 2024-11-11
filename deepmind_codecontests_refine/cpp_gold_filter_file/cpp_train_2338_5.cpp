#include <bits/stdc++.h>
using namespace std;
long long s[500010], ss[500010];
map<long long, int> m;
vector<vector<int> > v;
int main() {
  long long n, c = 1, cnt = 0;
  cin >> n;
  v.resize(n + 1);
  for (int i = 1; i <= n; i++) scanf("%lld", &s[i]);
  for (int i = n; i > 0; i--) {
    ss[i] = s[i] + ss[i + 1];
    if (!m[ss[i]]) m[ss[i]] = c++;
    v[m[ss[i]]].push_back(i);
  }
  for (int i = 1; i <= n; i++) s[i] += s[i - 1];
  for (int i = 1; i < c; i++) sort(v[i].begin(), v[i].end());
  for (int i = 1; i <= n; i++) {
    if (m[s[i]] && 3 * s[i] == s[n]) {
      vector<int>::iterator idx =
          lower_bound(v[m[s[i]]].begin(), v[m[s[i]]].end(), (i + 2));
      cnt += v[m[s[i]]].size() - (idx - v[m[s[i]]].begin());
    }
  }
  cout << cnt;
  return 0;
}
