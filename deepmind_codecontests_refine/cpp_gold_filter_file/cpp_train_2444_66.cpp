#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000001];
int visited[1000001] = {0};
int isCyclicUtil(int a, int parent) {
  visited[a] = 1;
  vector<int>::iterator i;
  for (i = v[a].begin(); i != v[a].end(); ++i) {
    if (visited[*i] == 0) {
      if (isCyclicUtil(*i, a)) return 1;
    } else if (*i != parent)
      return 1;
  }
  return 0;
}
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  int l = n * m;
  int r, w;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j + 1 <= m - 1) {
        if (s[i][j] == s[i][j + 1]) {
          r = (m * i) + j;
          w = (m * i) + (j + 1);
          v[r].push_back(w);
        }
      }
      if ((i - 1) >= 0) {
        if (s[i][j] == s[i - 1][j]) {
          r = (m * i) + j;
          w = (m * (i - 1)) + j;
          v[r].push_back(w);
        }
      }
      if ((j - 1) >= 0) {
        if (s[i][j] == s[i][j - 1]) {
          r = (m * i) + j;
          w = (m * i) + (j - 1);
          v[r].push_back(w);
        }
      }
      if ((i + 1) < n) {
        if (s[i][j] == s[i + 1][j]) {
          r = (m * i) + j;
          w = (m * (i + 1)) + j;
          v[r].push_back(w);
        }
      }
    }
  }
  int y = 0;
  for (int i = 0; i < l; i++) {
    if (visited[i] == 0) {
      if (isCyclicUtil(i, -1)) {
        y++;
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
}
