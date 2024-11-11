#include <bits/stdc++.h>
using namespace std;
const int Max = 510;
int arr[Max][Max];
int ps[Max][Max];
bool check(int i, int j);
int calcPs(int minX, int minY, int maxX, int maxY);
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      if (s[j] == '0')
        arr[i][j] = 0;
      else
        arr[i][j] = 1;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + check(i, j);
    }
  }
  int result = 0;
  for (int i = 1; i < n - 1; i++) {
    for (int j = i; j < n - 1; j++) {
      int l = 1;
      int r = 1;
      while (r < m - 1 && l < m - 1) {
        int calcedPs = calcPs(i, l, j, r);
        if (calcedPs >= k) {
          result += m - r - 1;
          l++;
        } else
          r++;
      }
    }
  }
  cout << result;
}
bool check(int i, int j) {
  return arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j] == 1 &&
         arr[i][j - 1] == 1 && arr[i - 1][j] == 1;
}
int calcPs(int minX, int minY, int maxX, int maxY) {
  minX--;
  minY--;
  return ps[maxX][maxY] - ps[minX][maxY] - ps[maxX][minY] + ps[minX][minY];
}
