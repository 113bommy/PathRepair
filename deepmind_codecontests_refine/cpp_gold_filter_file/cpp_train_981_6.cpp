#include <bits/stdc++.h>
using namespace std;
int otv[2001];
char ch[2001][2001];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int I = 1, j = i - 1; j >= 0 && I < n; j--, I++) {
      if (ch[I][j] == 'R') otv[i]++;
    }
    for (int I = 1, j = i + 1; j < m && I < n; j++, I++) {
      if (ch[I][j] == 'L') otv[i]++;
    }
    for (int I = 2, j = i; I < n; I += 2) {
      if (ch[I][j] == 'U') otv[i]++;
    }
    cout << otv[i] << " ";
  }
  return 0;
}
