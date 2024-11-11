#include <bits/stdc++.h>
using namespace std;
const int MX = 1000000;
const int delta = 1000000 + 3;
int row[MX], col[MX], n, m;
char c;
long long ans;
void otp() {
  cout << 0 << endl;
  exit(0);
}
int main() {
  cin >> n >> m;
  memset(row, -1, sizeof(row));
  memset(col, -1, sizeof(col));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> c;
      if (c != '.') {
        int q = j, p = i;
        if (c == '2')
          p++;
        else if (c == '3')
          q++, p++;
        else if (c == '4')
          q++;
        if (row[i] == -1)
          row[i] = 1 << (q % 2);
        else if (row[i] != 1 << (q % 2))
          otp();
        if (col[j] == -1)
          col[j] = 1 << (p % 2);
        else if (col[j] != 1 << (p % 2))
          otp();
      }
    }
  ans = 1;
  for (int i = 0; i < n; i++)
    if (row[i] == -1) {
      ans = (ans * 2) % delta;
    }
  for (int i = 0; i < m; i++)
    if (col[i] == -1) {
      ans = (ans * 2) % delta;
    }
  cout << ans << endl;
  return 0;
}
