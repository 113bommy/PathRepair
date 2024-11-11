#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1001;
int n, m, l, z, a[maxn], b[maxn];
string s[1001];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*') a[i]++;
  }
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (s[j][i] == '*') b[i]++;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*') l = l + (b[j] - 1) * (a[i] - 1);
  cout << l;
  return 0;
}
