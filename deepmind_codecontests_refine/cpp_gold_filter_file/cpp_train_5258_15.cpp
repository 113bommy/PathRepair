#include <bits/stdc++.h>
using namespace std;
int n, t, g, k, s;
string s1, s2;
vector<char> ans;
vector<int> giong, khac;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n >> t >> s1 >> s2;
  for (int i = 0; i < n; i++)
    if (s1[i] == s2[i])
      giong.push_back(i);
    else
      khac.push_back(i);
  for (int i = 1; i <= n; i++) ans.push_back(' ');
  s = n - t;
  g = giong.size(), k = khac.size();
  int doi = (k + 1) >> 1;
  if (doi > t || n < t) {
    cout << -1;
    return 0;
  }
  int dem = 0;
  for (int i = 0; i < g; i++) {
    int u = giong[i];
    if (dem < s)
      ans[u] = s1[u], dem++;
    else
      ans[u] = (s1[u] == 'z' ? 'a' : s1[u] + 1);
  }
  int las = k - 1;
  if (k & 1) {
    las--;
    int u = khac[k - 1];
    for (int i = 'a'; i <= 'z'; i++)
      if (i != s1[u] && i != s2[u]) {
        ans[u] = i;
        break;
      }
  }
  for (int i = 0; i <= las; i += 2) {
    int u = khac[i], v = khac[i + 1];
    if (dem < s) {
      ans[u] = s1[u];
      ans[v] = s2[v];
      dem++;
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
