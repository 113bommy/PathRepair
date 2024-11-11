#include <bits/stdc++.h>
using namespace std;
int n;
string s1, s2;
vector<int> a, b, c, d;
void solve(int p, int q, int r, int s) {
  vector<int> ans;
  for (int i = (int)1; i <= (int)p; i++) ans.push_back(a[i - 1]);
  for (int i = (int)1; i <= (int)q; i++) ans.push_back(b[i - 1]);
  for (int i = (int)1; i <= (int)r; i++) ans.push_back(c[i - 1]);
  for (int i = (int)1; i <= (int)s; i++) ans.push_back(d[i - 1]);
  for (auto e : ans) cout << e + 1 << " ";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s1 >> s2;
  for (int i = (int)0; i <= (int)n - 1; i++) {
    if (s1[i] == '0' && s2[i] == '0')
      a.push_back(i);
    else if (s1[i] == '0' && s2[i] == '1')
      b.push_back(i);
    else if (s1[i] == '1' && s2[i] == '0')
      c.push_back(i);
    else if (s1[i] == '1' && s2[i] == '1')
      d.push_back(i);
  }
  int tar = n / 2 - (int)b.size() - (int)d.size();
  for (int i = (int)0; i <= (int)(int)d.size(); i++) {
    int xa = i + tar;
    if ((int)a.size() >= xa && xa >= 0) {
      for (int j = (int)0; j <= (int)(int)c.size(); j++) {
        int y = n / 2 - xa - i;
        if ((int)b.size() >= y && y >= 0) {
          solve(xa, y, j, i);
          exit(0);
          ;
        }
      }
    }
  }
  cout << "-1\n";
  return 0;
}
