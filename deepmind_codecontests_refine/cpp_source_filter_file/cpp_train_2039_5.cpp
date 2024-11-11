#include <bits/stdc++.h>
using namespace std;
string arf[1005], ars[1005];
string ans[1005];
void solve() {
  int n;
  cin >> n;
  map<string, vector<int> > f, s;
  int done[n];
  memset(done, 0, sizeof(done));
  ;
  for (int i = 0; i < (int)(n); i++) {
    string s1, s2;
    cin >> s1 >> s2;
    arf[i] = s1.substr(0, 3);
    ars[i] = s1.substr(0, 2) + s2.substr(0, 1);
    f[arf[i]].push_back(i);
    s[ars[i]].push_back(i);
  }
  map<string, int> final;
  for (auto i = f.begin(); i != f.end(); i++) {
    if (i->second.size() > 1) {
      for (int k = 0; k < i->second.size(); k++) {
        final[ars[i->second[k]]]++;
        ans[i->second[k]] = ars[i->second[k]];
        done[i->second[k]] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (done[i] == 0) {
      if (final[arf[i]] == 0) {
        final[arf[i]] = 1;
        ans[i] = arf[i];
      } else if (final[ars[i]] == 0) {
        final[ars[i]] = 1;
        ans[i] = ars[i];
      } else {
        cout << "NO";
        return;
      }
    }
  }
  for (auto i = final.begin(); i != final.end(); i++) {
    if (i->second > 1) {
      cout << "NO";
      return;
    }
  }
  cout << "YES\n";
  for (int i = 0; i < (int)(n); i++) {
    cout << ans[i] << '\n';
  }
}
int main() {
  cin.tie(0);
  cout.tie(0);
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  int TC = 1;
  for (int ZZ = 1; ZZ <= TC; ZZ++) {
    clock_t start = clock();
    solve();
    clock_t end = clock();
    cerr << "Time: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds"
         << '\n';
  }
  return 0;
}
