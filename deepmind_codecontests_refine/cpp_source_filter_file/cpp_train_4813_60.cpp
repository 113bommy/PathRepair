#include <bits/stdc++.h>
using namespace std;
long long t, a, b, c, res, A, B, C, temp, tempA, tempB, tempC, tempX,
    f[10005][100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (long long i = 1; i <= 10000; i++) {
    f[i][0] = 0;
    tempX = sqrt(i);
    for (long long j = 1; j <= tempX; j++)
      if (i % j == 0) {
        f[i][++f[i][0]] = j;
        f[i][++f[i][0]] = i / j;
      }
    if (tempX * tempX == i) f[i][0]--;
    sort(f[i] + 1, f[i] + 1 + f[i][0]);
  }
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    res = -1;
    for (long long i = 1; i <= 10000; i++) {
      temp = llabs(b - i);
      tempB = i;
      if (a < i) {
        tempX = lower_bound(f[i] + 1, f[i] + 1 + f[i][0], a) - f[i];
        if (tempX == 1) {
          tempA = 1;
          temp += a - 1;
        } else {
          if ((a - f[i][tempX - 1]) < (f[i][tempX] - a)) {
            tempA = f[i][tempX - 1];
            temp += a - f[i][tempX - 1];
          } else {
            tempA = f[i][tempX];
            temp += f[i][tempX] - a;
          }
        }
      }
      if (a == i) tempA = i;
      if (a > i) {
        temp += a - i;
        tempA = i;
      }
      if (c < i) {
        temp += i - c;
        tempC = i;
      }
      if (c == i) tempC = i;
      if (c > i) {
        if ((c - c / i * i) < ((c / i + 1) * i - c)) {
          temp += c - c / i * i;
          tempC = c / i * i;
        } else {
          temp += (c / i + 1) * i - c;
          tempC = (c / i + 1) * i;
        }
      }
      if (temp < res || res == -1) {
        res = temp;
        A = tempA;
        B = tempB;
        C = tempC;
      }
    }
    cout << res << "\n" << A << " " << B << " " << C << "\n";
  }
  return 0;
}
