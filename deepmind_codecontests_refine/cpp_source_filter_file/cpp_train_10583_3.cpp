#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void solve(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    vector<string> forb(n);
    for (int i = 0; i <= n - 1; i++) {
      in >> forb[i];
    }
    string w;
    in >> w;
    string c;
    in >> c;
    char let = c[0];
    string ans((int)w.size(), ' ');
    for (int i = 0; i <= n - 1; i++) {
      if ((int)forb[i].size() < (int)w.size()) {
        for (int j = 0; j <= (int)w.size() - 1; j++) {
          int cnt = 0;
          for (int k = 0; k <= (int)forb[i].size() - 1; k++) {
            if (tolower(w[j + k]) == tolower(forb[i][k])) cnt++;
          }
          if (cnt == (int)forb[i].size()) {
            for (int k = 0; k <= (int)forb[i].size() - 1; k++) {
              if (tolower(w[j + k]) != tolower(let)) {
                if (isupper(w[j + k]))
                  ans[j + k] = (char)toupper(let);
                else
                  ans[j + k] = (char)tolower(let);
              } else {
                if (let == 'a') {
                  if (isupper(w[j + k]))
                    ans[j + k] = 'B';
                  else
                    ans[j + k] = 'b';
                } else {
                  if (isupper(w[j + k]))
                    ans[j + k] = 'A';
                  else
                    ans[j + k] = 'a';
                }
              }
            }
          }
        }
      }
    }
    for (int i = 0; i <= (int)ans.size() - 1; i++) {
      if (ans[i] == ' ') ans[i] = w[i];
    }
    out << ans << '\n';
    return;
  }
};
void solve(std::istream& in, std::ostream& out) {
  out << std::setprecision(12);
  Solution solution;
  solution.solve(in, out);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  istream& in = cin;
  ostream& out = cout;
  solve(in, out);
  return 0;
}
