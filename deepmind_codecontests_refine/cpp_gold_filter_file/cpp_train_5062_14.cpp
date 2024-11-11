#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> mayusculas;
set<int> mayfinal;
vector<int> v[100005];
void dfs(int p) {
  mayfinal.insert(p);
  for (int i = 0; i < (int)v[p].size(); i++) dfs(v[p][i]);
}
bool comparar(int a, int b) {
  int a1 = mayfinal.count(a);
  int b1 = mayfinal.count(b);
  if (a1 and not b1) return true;
  if (not a1 and b1) return false;
  return a <= b;
}
int main() {
  cin >> n >> m;
  int l[n];
  vector<int> s[n];
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    int aux;
    for (int j = 0; j < l[i]; j++) {
      cin >> aux;
      s[i].push_back(aux);
    }
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < min(l[i], l[i + 1]); j++)
      if (s[i][j] < s[i + 1][j]) {
        v[s[i + 1][j]].push_back(s[i][j]);
        break;
      } else if (s[i][j] > s[i + 1][j]) {
        mayusculas.insert(s[i][j]);
        break;
      }
  for (set<int>::iterator it = mayusculas.begin(); it != mayusculas.end(); it++)
    dfs(*it);
  for (int i = 0; i < n - 1; i++) {
    int j;
    for (j = 0; j < min(l[i], l[i + 1]); j++)
      if (s[i][j] != s[i + 1][j]) {
        if (!comparar(s[i][j], s[i + 1][j])) {
          cout << "No" << endl;
          return 0;
        }
        break;
      }
    if (j == min(l[i], l[i + 1]) and l[i] > l[i + 1]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  cout << mayfinal.size() << endl;
  for (set<int>::iterator it = mayfinal.begin(); it != mayfinal.end(); it++)
    cout << *it << ' ';
  cout << endl;
}
