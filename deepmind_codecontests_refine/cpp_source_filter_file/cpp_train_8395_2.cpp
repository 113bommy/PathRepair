#include <bits/stdc++.h>
using namespace std;
void search(vector<string>& t, vector<bool>& usedi, vector<bool>& usedj, int k,
            vector<int>& js) {}
int main() {
  int n, m;
  cin >> n >> m;
  vector<string> t(n);
  for (auto& x : t) {
    cin >> x;
  }
  vector<bool> usedi(n);
  vector<bool> usedj(m);
  bool ans = true;
  for (int i = 0; i < n; i++) {
    if (usedi[i] == false) {
      vector<int> js;
      usedi[i] = true;
      for (int j = 0; j < t[i].size(); j++) {
        if (t[i][j] == '#') {
          js.push_back(j);
          usedj[j] = false;
        }
      }
      for (int k = 0; k < n; k++) {
        if (usedi[k] == false) {
          int c = m - js.size();
          int d = js.size();
          for (int l = 0; l < m; l++) {
            if (t[k][l] == '.') c--;
          }
          for (auto& x : js) {
            if (t[k][x] == '#') {
              d--;
            }
          }
          if (c + d == 0)
            usedi[k] = true;
          else if (d != js.size()) {
            ans = false;
            break;
          }
        }
      }
    }
  }
  printf((ans) ? "YES" : "NO");
  return 0;
}
