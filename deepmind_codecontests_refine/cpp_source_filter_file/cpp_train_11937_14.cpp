#include <bits/stdc++.h>
using namespace std;
const int N = 109;
int n;
int a[4];
string s[4][110];
int main() {
  cin >> n;
  for (int p = 0; p < 4; p++) {
    int num = 0;
    for (int i = 0; i < n; i++) {
      cin >> s[p][i];
      for (int j = 0; j < n; j++) {
        int x1 = i + j;
        if (((x1 & 1) == 0) and s[p][i][j] == '0')
          num++;
        else if (x1 & 1 and s[p][i][j] == '1')
          num++;
      }
      a[p] = num;
    }
  }
  sort(a, a + n);
  cout << a[0] + a[1] + (n * n - a[2]) + (n * n - a[3]) << '\n';
}
