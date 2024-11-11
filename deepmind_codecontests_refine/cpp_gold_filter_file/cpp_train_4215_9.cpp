#include <bits/stdc++.h>
using namespace std;
string S[100];
vector<int> G[26];
int color[26];
int key = 0;
vector<int> ans;
void dfs(int s) {
  color[s] = 1;
  for (int i = 0; i < G[s].size(); i++) {
    int v = G[s][i];
    if (color[v] == 0) {
      dfs(v);
    }
    if (color[v] == 1) {
      key = 1;
    }
  }
  color[s] = 2;
  ans.push_back(s);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < n - 1; i++) {
    int j = 0;
    while ((j < S[i].size()) && (j < S[i + 1].size()) &&
           (S[i][j] == S[i + 1][j]))
      j++;
    if (j == S[i + 1].size())
      key = 1;
    else {
      if (j != S[i].size()) {
        G[S[i][j] - 'a'].push_back(S[i + 1][j] - 'a');
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    if (color[i] == 0) {
      dfs(i);
    }
  }
  reverse(ans.begin(), ans.end());
  if (key == 1)
    cout << "Impossible" << endl;
  else {
    for (int i = 0; i < ans.size(); i++) cout << (char)(ans[i] + 'a');
    cout << endl;
  }
}
