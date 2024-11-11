#include <bits/stdc++.h>
using namespace std;
struct elements {
  bool canBuild;
  int digits[7];
};
struct path {
  int a, b;
};
elements s[7 * 6 + 2];
int d[10];
void Try(int i, int sum) {
  if (i > 6) {
    s[sum].canBuild = true;
    for (int j = 1; j <= 6; j++) s[sum].digits[j] = d[j];
    return;
  }
  d[i] = 0;
  Try(i + 1, sum);
  d[i] = 4;
  Try(i + 1, sum + 4);
  d[i] = 7;
  Try(i + 1, sum + 7);
}
void init() {
  for (int i = 0; i <= 7 * 6; i++) s[i].canBuild = false;
  Try(1, 0);
}
int main() {
  init();
  int testCases;
  cin >> testCases;
  while (testCases--) {
    long long n;
    cin >> n;
    int digits[20], m = 0;
    while (n > 0) {
      m++;
      digits[m] = n % 10;
      n = n / 10;
    }
    bool f[m + 5][5];
    path trace[m + 5][5];
    memset(f, false, sizeof(f));
    f[0][0] = true;
    for (int i = 0; i <= m - 1; i++) {
      for (int j = 0; j <= 4; j++) {
        if (f[i][j]) {
          for (int k = 0; k <= 42; k++) {
            if ((s[k].canBuild) && (j + k % 10 == digits[i + 1])) {
              int x = (j + k);
              f[i + 1][x / 10] = true;
              trace[i + 1][x / 10].a = j;
              trace[i + 1][x / 10].b = k;
            }
          }
        }
      }
    }
    if (f[m][0]) {
      long long res[10], j = 0;
      memset(res, 0, sizeof(res));
      while (m > 0) {
        int x = trace[m][j].b;
        for (int i = 1; i <= 6; i++) res[i] = res[i] * 10 + s[x].digits[i];
        j = trace[m][j].a;
        m--;
      }
      for (int i = 1; i <= 6; i++) cout << res[i] << " ";
      cout << endl;
    } else
      cout << -1 << endl;
  }
}
