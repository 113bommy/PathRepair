#include <bits/stdc++.h>
using namespace std;
vector<int> out;
vector<int> used(50);
vector<vector<int> > arr(1000);
int t = 0;
bool dfs(char v) {
  used[v] = 1;
  for (int i = 0; i < arr[v].size(); i++)
    if (used[arr[v][i]] == 0) {
      if (dfs(arr[v][i])) return 1;
    } else if (used[arr[v][i]] == 1) {
      return 1;
    }
  used[v] = 2;
  out.push_back(v);
  return 0;
}
int main() {
  int n;
  cin >> n;
  string s2;
  cin >> s2;
  for (int i = 0; i < n - 1; i++) {
    string s1;
    cin >> s1;
    int k = -1;
    for (int j = 0; j < min(s1.length(), s2.length()) && k < 0; j++) {
      if (k < 0 && s1[j] != s2[j]) k = j;
    }
    if (k == -1 && s1.length() < s2.length()) {
      cout << "Impossible";
      return 0;
    }
    if (k >= 0) {
      arr[s1[k] - 'a'].push_back(s2[k] - 'a');
    }
    s2 = s1;
  }
  for (int i = 0; i <= 'z' - 'a'; i++)
    if (!used[i]) {
      if (dfs(i)) {
        cout << "Impossible";
        return 0;
      }
    }
  for (int i = 0; i < out.size(); i++) {
    cout << char(out[i] + 'a');
  }
  return 0;
}
