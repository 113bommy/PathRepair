#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int nmax = 10000;
const double E = 1e-8;
const double PI = acos(-1);
int n, m, stest;
bool c[300][300];
string a[nmax];
int deg[300], Fre[300];
bool check(int u, int v) {
  if (u % 2 == 1) return true;
  if (u % 4 == 0 && v == 1) return true;
  if (u % 4 == 2 && v == m) return true;
  return false;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) {
    int k = 0;
    while (k < min((int)a[i - 1].size(), (int)a[i].size()) &&
           a[i][k] == a[i - 1][k])
      k++;
    if (k == min((int)a[i - 1].size(), (int)a[i].size())) {
      if ((int)a[i - 1].size() <= (int)a[i].size())
        continue;
      else {
        cout << "Impossible" << endl;
        return 0;
      }
    } else {
      c[a[i - 1][k]][a[i][k]] = true;
    }
  }
  for (int i = 'a'; i <= 'z'; i++)
    for (int j = 'a'; j <= 'z'; j++)
      if (c[i][j]) {
        deg[j]++;
      }
  vector<char> res;
  for (int i = 'a'; i <= 'z'; i++) Fre[i] = true;
  for (int step = 1; step <= 26; step++) {
    char u = ' ';
    for (int i = 'a'; i <= 'z'; i++)
      if (Fre[i] && deg[i] == 0) {
        u = i;
        break;
      }
    if (u == ' ') {
      cout << "Impossible" << endl;
      return 0;
    }
    Fre[u] = false;
    for (int i = 'a'; i <= 'z'; i++)
      if (Fre[i] && c[u][i]) deg[i]--;
    res.push_back(u);
  }
  for (int i = 1; i <= 26; i++) cout << res[i - 1];
  return 0;
}
