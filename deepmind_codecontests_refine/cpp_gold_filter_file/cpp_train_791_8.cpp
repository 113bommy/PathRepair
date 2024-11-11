#include <bits/stdc++.h>
using namespace std;
map<int, char> m[3];
int n;
int fin(int x) {
  int a, b, c;
  a = x / 100;
  b = (x / 10) % 10;
  c = x % 10;
  if (x < 10) {
    for (int i = 0; i < n; i++) {
      if (m[i][x] == 'y') return 1;
    }
  } else if (x < 100) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++)
        if ((m[i][b] == 'y' && m[j][c] == 'y') ||
            (m[i][c] == 'y' && m[j][b] == 'y'))
          return 1;
    }
  } else {
    if (m[0][a] == 'y' && m[1][b] == 'y' && m[2][c] == 'y') return 1;
    if (m[0][a] == 'y' && m[1][c] == 'y' && m[2][b] == 'y') return 1;
    if (m[0][b] == 'y' && m[1][a] == 'y' && m[2][c] == 'y') return 1;
    if (m[0][b] == 'y' && m[1][c] == 'y' && m[2][a] == 'y') return 1;
    if (m[0][c] == 'y' && m[1][b] == 'y' && m[2][a] == 'y') return 1;
    if (m[0][c] == 'y' && m[1][a] == 'y' && m[2][b] == 'y') return 1;
  }
  return 0;
}
int main() {
  int x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> x;
      m[i][x] = 'y';
    }
  }
  int flag, i;
  for (i = 1; i < pow(10, n); i++) {
    flag = fin(i);
    if (flag == 0) break;
  }
  cout << i - 1;
}
