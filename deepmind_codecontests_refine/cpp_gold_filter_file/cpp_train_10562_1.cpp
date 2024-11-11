#include <bits/stdc++.h>
using namespace std;
int n, m;
string a, b;
int fx[1000010], fy[1000010], ans = 1;
int main() {
  cin >> n >> m >> a >> b;
  for (int i = 0; i < n; i++) {
    if (a[i] == '>') {
      fx[i] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    if (b[i] == '^') {
      fy[i] = 1;
    }
  }
  if (fx[0] != fy[0]) ans = 0;
  if (fx[0] == fy[m - 1]) ans = 0;
  if (fx[n - 1] == fy[0]) ans = 0;
  if (fx[n - 1] != fy[m - 1]) ans = 0;
  if (ans)
    cout << "YES";
  else
    cout << "NO";
}
