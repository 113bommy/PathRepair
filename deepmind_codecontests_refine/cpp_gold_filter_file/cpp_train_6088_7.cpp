#include <bits/stdc++.h>
using namespace std;
vector<int> g[500];
int dfs(int v, int par) {
  if (g[v].size() == 1 && g[v][0] == par) {
    return 0;
  }
  int max = -1, temp;
  for (int x : g[v]) {
    if (x != par) {
      temp = dfs(x, v);
      if (max < temp) {
        max = temp;
      }
    }
  }
  return max + 1;
}
int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  int number = 1;
  string str;
  int t1, t2;
  mp["polycarp"] = 1;
  number = 2;
  for (int i = 0; i < n; i++) {
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    if (mp[str] == 0) {
      mp[str] = number;
      number++;
    }
    t1 = mp[str];
    cin >> str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    if (mp[str] == 0) {
      mp[str] = number;
      number++;
    }
    t2 = mp[str];
    g[t1].push_back(t2);
    g[t2].push_back(t1);
  }
  cout << dfs(1, 0) + 1 << endl;
  return 0;
}
