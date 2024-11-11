#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300001;
int n, p;
int w[MAXN], a[MAXN], b[MAXN];
long long s[MAXN], ans[MAXN];
int main(int argc, char *argv[]) {
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> w[i];
  cin >> p;
  for (int i = 0; i < (p); ++i) cin >> a[i] >> b[i];
  map<int, vector<int> > t;
  for (int i = 0; i < (p); ++i) t[b[i]].push_back(i);
  for (typeof(t.begin()) it = t.begin(); it != t.end(); it++) {
    int dif = it->first;
    if ((int)(it->second).size() > dif / 2) {
      for (int i = (1); i <= (n); ++i) s[i] = w[i];
      for (int i = n - dif; i >= 1; --i) s[i] += s[i + dif];
      for (int i = 0; i < ((int)(it->second).size()); ++i) {
        int id = (it->second)[i];
        ans[id] = s[a[id]];
      }
    } else
      for (int i = 0; i < ((int)(it->second).size()); ++i) {
        int id = (it->second)[i];
        ans[id] = 0;
        for (int j = a[id]; j <= n; j += b[id]) ans[id] += w[j];
      }
  }
  for (int i = 0; i < (p); ++i) cout << ans[i] << endl;
}
