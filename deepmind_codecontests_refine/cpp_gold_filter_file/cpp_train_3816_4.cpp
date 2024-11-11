#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > g;
map<int, bool> vi;
void addedge(int x, int y) {
  g[x].push_back(y);
  g[y].push_back(x);
}
void bfs(int x) {
  map<int, bool> v;
  queue<int> q;
  q.push(x);
  v[x] = true;
  while (!q.empty()) {
    int n = q.front();
    cout << n << " ";
    q.pop();
    for (int i = 0; i < g[n].size(); i++) {
      if (v[g[n][i]] == false) {
        q.push(g[n][i]);
        v[g[n][i]] = true;
      }
    }
  }
}
void dfs(int x) {
  cout << x << " ";
  vi[x] = true;
  for (int i = 0; i < g[x].size(); i++) {
    if (!vi[g[x][i]]) {
      dfs(g[x][i]);
    }
  }
}
bool compare(long long int a, long long int b) {
  return ((long long int)a == (long long int)b);
}
int main() {
  long long int r, c;
  cin >> r >> c;
  string s[r];
  long long int set = 0;
  for (long long int i = 0; i < r; i++) {
    cin >> s[i];
    for (long long int j = 0; j < c; j++) {
      if ((s[i])[j] == 'W' && (s[i])[j - 1] == 'S') {
        set = 1;
      }
      if ((s[i])[j] == 'W' && j + 1 < c && (s[i])[j + 1] == 'S') {
        set = 1;
      }
      if ((s[i])[j] == 'W' && i - 1 >= 0 && (s[i - 1])[j] == 'S') {
        set = 1;
      }
      if ((s[i])[j] == '.') {
        (s[i])[j] = 'D';
      }
    }
  }
  for (long long int i = 0; i < r; i++) {
    long long int j;
    for (long long int j = 0; j < c; j++) {
      if ((s[i])[j] == 'W' && i + 1 < r && (s[i + 1])[j] == 'S') {
        set = 1;
      }
    }
  }
  if (set == 1) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (long long int i = 0; i < r; i++) {
      cout << s[i] << endl;
    }
  }
}
