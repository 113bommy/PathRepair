#include <bits/stdc++.h>
const int minINF = 1e5;
const int INF = 1e9;
const long long INFL = 1e18;
const int MAX = 1e5 + 100;
bool prime(long long n) {
  if (n <= 1) return false;
  if (n == 2) return true;
  for (int x = 2; x * x <= n; x++) {
    if (n % x == 0) return false;
  }
  return true;
}
using namespace std;
int m1[] = {0, 1, 2, 3};
int xdir[] = {-1, 1, 0, 0};
int ydir[] = {0, 0, 1, -1};
int n, m;
char s[501][501];
bool isValid(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m) return false;
  return true;
}
bool isWolf(char a) {
  if (a == 'W')
    return true;
  else
    return false;
}
bool isDog(char a) {
  if (a == 'D')
    return true;
  else
    return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        for (int k = 0; k < 4; k++) {
          int x = i + xdir[k];
          int y = j + ydir[k];
          if (isValid(x, y)) {
            if (isWolf(s[x][y]))
              return cout << "No", 0;
            else {
              if (s[x][y] == 'S')
                continue;
              else
                s[x][y] = 'D';
            }
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << s[i][j];
    cout << endl;
  }
}
