#include <bits/stdc++.h>
using namespace std;
int n, cnt, col[110], row[110];
char ary[110][110];
bool found;
void __col() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (ary[j][i] == '.') {
        cout << j << " " << i << "\n";
        break;
      }
  exit(0);
}
void __row() {
  for (int j = 1; j <= n; j++)
    for (int i = 1; i <= n; i++)
      if (ary[j][i] == '.') {
        cout << j << " " << i << "\n";
        break;
      }
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      cin >> ary[i][j];
      if (ary[i][j] == 'E') ++row[i], ++col[j];
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (row[i] == n && col[j] == n) {
        cout << -1 << "\n";
        return 0;
      }
  for (int j = 1; j <= n; j++) {
    if (row[j] == n) __col();
    __row();
  }
  return 0;
}
