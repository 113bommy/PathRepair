#include <bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;
const double PI = 2 * acos(0.0);
int main() {
  int n, m, p;
  while (cin >> n >> m >> p) {
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> M;
    for (int i = 0; i < m; ++i) {
      cin >> b[i];
      ++M[b[i]];
    }
    int cond = M.size();
    vector<int> ans;
    for (int i = 0; i < p; ++i) {
      if ((long long)i + (long long)m * p > (long long)n) break;
      map<int, int> S;
      set<int> in;
      int j = i;
      for (; j < n; j += p) {
        S[a[j]]++;
        if (S[a[j]] == M[a[j]])
          in.insert(a[j]);
        else if (S[a[j]] != M[a[j]])
          in.erase(a[j]);
        int first = j - (m - 1) * p;
        if (first >= 0) {
          if (in.size() == cond) {
            ans.push_back(first + 1);
          }
          S[a[first]]--;
          if (S[a[first]] != M[a[first]])
            in.erase(a[first]);
          else if (M[a[first]])
            in.insert(a[first]);
        }
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    if (ans.size() > 0) {
      cout << ans[0];
      for (int i = 1; i < (int)ans.size(); ++i) cout << " " << ans[i];
      cout << endl;
    }
  }
  return 0;
}
