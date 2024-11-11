#include <bits/stdc++.h>
using namespace std;
int n, t, slg, slk, s;
string s1, s2;
vector<char> ans;
vector<int> giong, khac;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> t >> s1 >> s2;
  s = n - t;
  for (int i = 0; i < n; i++) {
    ans.push_back(' ');
    if (s1[i] == s2[i])
      giong.push_back(i);
    else
      khac.push_back(i);
  }
  slg = giong.size();
  slk = khac.size();
  int thaydoi = (slk + 1) >> 1;
  if (thaydoi > t || n < t) {
    cout << -1;
    return 0;
  }
  int dem = 0;
  for (int i = 0; i < slg; i++) {
    int u = giong[i];
    if (dem < s) {
      ans[u] = s1[u];
      dem++;
    } else
      ans[u] = (s1[u] == 'z' ? 'a' : s1[u] + 1);
  }
  int last = slk - 1;
  if (slk % 2) {
    for (int i = 'a'; i <= 'z'; i++)
      if (i != s1[khac[slk - 1]] && i != s2[khac[slk - 1]]) {
        ans[khac[slk - 1]] = i;
        break;
      }
    last--;
  }
  for (int i = 0; i <= last; i += 2) {
    int u = khac[i], v = khac[i + 1];
    if (dem < s) {
      ans[u] = s1[u];
      ans[v] = s1[v];
      dem += 2;
    } else {
      for (int i = 'a'; i <= 'z'; i++)
        if (i != s1[u] && i != s2[u]) {
          ans[u] = i;
          break;
        }
      for (int i = 'a'; i <= 'z'; i++)
        if (i != s1[v] && i != s2[v]) {
          ans[v] = i;
          break;
        }
    }
  }
  for (int i = 0; i < n; i++) cout << ans[i];
  return 0;
}
