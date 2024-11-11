#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
vector<int> nn;
int s[200005], t = -1;
void dfss(int x) {
  if (s[x]) return;
  s[x] = 1;
  nn.push_back(x);
  for (int i = 0; i < v[x].size(); i++) dfss(v[x][i]);
  return;
}
void dfs(int x) {
  int ss = 0;
  if (x != t) ss++;
  for (int i = 0; i < v[x].size(); i++) {
    dfs(v[x][i]);
    if (s[v[x][i]] == 0) ss++;
  }
  if (ss % 2 == 0) {
    dfss(x);
  }
  return;
}
int main() {
  int n;
  cin >> n;
  int j;
  for (int i = 1; i <= n; i++) {
    cin >> j;
    if (j == 0) {
      t = i;
      continue;
    }
    v[j].push_back(i);
  }
  dfs(t);
  if (nn.size() != n) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (vector<int>::iterator i = nn.begin(); i != nn.end(); i++) {
    cout << *i << endl;
  }
}
