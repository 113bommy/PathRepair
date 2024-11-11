#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char c1[20], c2[20];
  for (int i = 0; i < n; i++) cin >> c1[i];
  for (int i = 0; i < m; i++) cin >> c2[i];
  bool b1 =
      (c1[0] == '>' && c1[n - 1] == '<' && c2[0] == '^' && c2[m - 1] == 'v');
  bool b2 =
      (c1[0] == '<' && c1[n - 1] == '>' && c2[0] == 'v' && c2[m - 1] == '^');
  if (b1 || b2)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
