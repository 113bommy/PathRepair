#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
bool can[MAXN][5];
vector<string> sol;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  s += "###";
  can[n][2] = can[n][3] = true;
  for (int i = n - 1; i >= 0; --i) {
    if (i <= 4) break;
    if (can[i + 2][2] && s.substr(i, 2) != s.substr(i + 2, 2) ||
        can[i + 3][3]) {
      can[i][2] = true;
    }
    if (can[i + 3][2] ||
        can[i + 3][3] && s.substr(i, 3) != s.substr(i + 3, 3)) {
      can[i][3] = true;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i < 5) continue;
    if (can[i][2]) sol.push_back(s.substr(i, 2));
    if (can[i][3]) sol.push_back(s.substr(i, 3));
  }
  int sz = 0;
  sort(sol.begin(), sol.end());
  for (int i = 0; i < sol.size(); ++i) {
    if (!i || sol[i] != sol[i - 1]) sz++;
  }
  cout << sz << '\n';
  for (int i = 0; i < sol.size(); ++i) {
    if (!i || sol[i] != sol[i - 1]) cout << sol[i] << '\n';
  }
}
