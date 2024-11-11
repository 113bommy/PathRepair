#include <bits/stdc++.h>
using namespace std;
string s, ans;
vector<string> files;
int m, n, x;
vector<int> ind;
bool check(string t, string test) {
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '?') continue;
    if (t[i] != test[i]) return 0;
  }
  return (t.size() == test.size()) ? 1 : 0;
}
bool test(char c, int i) {
  for (int j = 0; j < ind.size(); j++)
    if (files[ind[j]][i] != c) return 0;
  return 1;
}
bool test2(int siz) {
  for (int i = 0; i < ind.size(); i++)
    if (files[ind[i]].size() != siz) return 0;
  return 1;
}
bool findV(int t) {
  for (int i = 0; i < ind.size(); i++)
    if (ind[i] == t) return 1;
  return 0;
}
int main() {
  cin >> m >> n;
  while (m-- && cin >> s) files.push_back(s);
  while (n-- && cin >> x) ind.push_back(x - 1);
  if (!test2(files[ind[0]].size())) return 0 * puts("No");
  for (int i = 0; i < files[ind[0]].size(); i++)
    if (test(files[ind[0]][i], i))
      ans += files[ind[0]][i];
    else
      ans += '?';
  for (int i = 0; i < files.size(); i++)
    if (check(ans, files[i]) && !findV(i)) return 0 * puts("No");
  cout << "Yes" << endl << ans << endl;
  return 0;
}
