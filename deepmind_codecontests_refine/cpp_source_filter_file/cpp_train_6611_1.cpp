#include <bits/stdc++.h>
using namespace std;
int n, m, b[100001], c[100001], f[100001];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++)
    if (c[f[i]] == 0)
      c[f[i]] = i + 1;
    else
      c[f[i]] = -1;
  for (int i = 0; i < n; i++)
    if (c[b[i]] == 0) {
      cout << "Impossible";
      return 0;
    }
  for (int i = 0; i < n; i++)
    if (c[b[i]] == -1) {
      cout << "Ambiguity";
      return 0;
    }
  cout << "Possible" << endl;
  for (int i = 0; i < m; i++) cout << c[b[i]] << " ";
  return 0;
}
