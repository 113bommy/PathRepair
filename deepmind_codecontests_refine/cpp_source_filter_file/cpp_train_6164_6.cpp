#include <bits/stdc++.h>
using namespace std;
vector<int> vec[200002];
int used[200002];
void connect(int a, int b) {
  vec[a].push_back(b);
  vec[b].push_back(a);
}
void dfs(int a) {
  used[a] = 1;
  for (int e : vec[a]) {
    if (!used[e]) dfs(e);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) {
      connect(i, n + c - 'a');
    }
  }
  int res = 0;
  for (int i = n; i < n + 26; i++) {
    if (!vec[i].empty() && !used[i]) {
      res++;
      dfs(i);
    }
  }
  cout << res;
}
