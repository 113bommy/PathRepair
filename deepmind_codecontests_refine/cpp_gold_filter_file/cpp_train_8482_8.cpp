#include <bits/stdc++.h>
using namespace std;
const long long OO = 1e18 + 10;
const int MOD = 1e9 + 7;
const double Pi = 3.141592653589793;
const int N = 2e5 + 5;
pair<long long, long long> a[N];
vector<int> p[N];
long long l[N], r[N], b[N];
int pa[N], push_back[N], res[N], cur = 0, n, m, mv = 0;
map<long long, int> mp;
bool cmpa(int x, int y) { return a[x] < a[y]; }
bool cmpb(int x, int y) { return b[x] < b[y]; }
int main() {
  cin >> n >> m;
  for (int i = (int)1; i <= (int)n; i++) cin >> l[i] >> r[i], pa[i] = i;
  for (int i = (int)1; i <= (int)n - 1; i++)
    a[i] = pair<long long, long long>(r[i + 1] - l[i], l[i + 1] - r[i]);
  n--;
  mp[OO] = 0;
  b[0] = 0;
  for (int i = (int)1; i <= (int)m; i++) cin >> b[i], push_back[i] = i;
  sort(pa + 1, pa + n + 1, cmpa);
  sort(push_back + 1, push_back + m + 1, cmpb);
  for (int i = (int)1; i <= (int)n; i++) {
    long long L = a[pa[i]].second, R = a[pa[i]].first;
    while (cur < m && b[push_back[cur + 1]] <= R) {
      long long d = b[push_back[++cur]];
      if (d > b[push_back[cur - 1]]) {
        mp[d] = ++mv;
        p[mv].push_back(push_back[cur]);
      } else
        p[mv].push_back(push_back[cur]);
    }
    map<long long, int>::iterator x = mp.map::lower_bound(L);
    long long v = (*x).first;
    int pos = (*x).second;
    if (v == OO) {
      cout << "No";
      return 0;
    }
    res[pa[i]] = p[pos].back();
    p[pos].pop_back();
    if (p[pos].empty()) mp.erase(v);
  }
  cout << "Yes" << endl;
  for (int i = (int)1; i <= (int)n; i++) cout << res[i] << " ";
}
