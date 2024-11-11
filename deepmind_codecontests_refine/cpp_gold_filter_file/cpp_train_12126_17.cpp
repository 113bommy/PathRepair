#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int n;
vector<int> graph[110];
string s[110];
int mp[30][30];
int in[30];
void toposort() {
  for (int i = 0; i < 26; i++)
    if (!in[i]) {
      cout << (char)(i + 'a');
      q.push(i);
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < graph[u].size(); i++) {
      int v = graph[u][i];
      in[v]--;
      if (in[v] == 0) {
        cout << (char)(v + 'a');
        q.push(v);
      }
    }
  }
  for (int i = 0; i < 26; i++)
    if (in[i] == -1) cout << (char)(i + 'a');
}
int main() {
  cin >> n;
  if (n == 1) {
    for (char c = 'a'; c <= 'z'; c++) cout << c;
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> s[i];
  memset(in, -1, sizeof(in));
  for (int i = n; i >= 1; i--)
    for (int j = i - 1; j >= 1; j--) {
      int l = 0;
      while (s[i][l] == s[j][l] && l <= min(s[i].length(), s[j].length())) l++;
      if (l == s[i].length()) {
        cout << "Impossible" << endl;
        return 0;
      }
      if (l == s[j].length()) continue;
      mp[s[i][l] - 'a'][s[j][l] - 'a'] = 1;
      if (in[s[j][l] - 'a'] == -1) in[s[j][l] - 'a'] = 0;
      in[s[i][l] - 'a'] += in[s[i][l] - 'a'] == -1 ? 2 : 1;
      graph[s[j][l] - 'a'].push_back(s[i][l] - 'a');
    }
  for (int k = 0; k < 26; k++)
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < 26; j++) mp[i][j] += mp[i][k] * mp[k][j];
  for (int i = 0; i < 26; i++)
    if (mp[i][i]) {
      cout << "Impossible" << endl;
      return 0;
    }
  toposort();
  return 0;
}
