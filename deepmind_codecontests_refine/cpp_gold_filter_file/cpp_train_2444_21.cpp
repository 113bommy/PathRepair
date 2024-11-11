#include <bits/stdc++.h>
using namespace std;
long long int n, m, flag = 0;
vector<string> v;
char A;
void dfs(long long int i, long long int j, long long int pi, long long int pj,
         long long int coun) {
  if ((i - 1 >= 0 && i - 1 == pi && j == pj && coun > 3) ||
      (i + 1 < n && i + 1 == pi && j == pj && coun > 3) ||
      (j - 1 >= 0 && i == pi && j - 1 == pj && coun > 3) ||
      (j + 1 < m && i == pi && j + 1 == pj && coun > 3)) {
    cout << "Yes";
    flag = 1;
    return;
  }
  v[i][j] = 'a';
  if (i + 1 < n && v[i + 1][j] == A && flag == 0)
    dfs(i + 1, j, pi, pj, coun + 1);
  if (i - 1 >= 0 && v[i - 1][j] == A && flag == 0)
    dfs(i - 1, j, pi, pj, coun + 1);
  if (j + 1 < m && v[i][j + 1] == A && flag == 0)
    dfs(i, j + 1, pi, pj, coun + 1);
  if (j - 1 >= 0 && v[i][j - 1] == A && flag == 0)
    dfs(i, j - 1, pi, pj, coun + 1);
  v[i][j] = A;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  long long int i, j;
  cin >> n >> m;
  string x;
  for (i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      A = v[i][j];
      v[i][j] = 'a';
      dfs(i, j, i, j, 1);
      v[i][j] = A;
      if (flag == 1) break;
    }
    if (flag == 1) break;
  }
  if (flag == 0) cout << "No";
  return (0);
}
