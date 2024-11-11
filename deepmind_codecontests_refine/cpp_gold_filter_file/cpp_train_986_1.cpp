#include <bits/stdc++.h>
using namespace std;
const int n = 1000;
const long mod = 1000000007;
int main() {
  int k, newk, newn;
  int* balls;
  long** cnk;
  long long rez;
  cin >> k;
  balls = new int[k];
  for (int i = 0; i < k; i++) cin >> balls[i];
  cnk = new long*[n + 1];
  for (int i = 0; i < n + 1; i++) cnk[i] = new long[n + 1];
  for (int i = 0; i < n + 1; i++) cnk[0][i] = 0;
  for (int i = 0; i < n + 1; i++) cnk[i][0] = 1;
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < n + 1; j++)
      cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1]) % mod;
  newn = balls[0];
  newk = 0;
  rez = 1;
  for (int i = 1; i < k; i++) {
    newk = balls[i] - 1;
    newn += balls[i];
    rez = (rez * cnk[newn - 1][newk]) % mod;
  }
  cout << rez;
  for (int i = 0; i < n + 1; i++) delete[] cnk[i];
  delete[] cnk;
  delete[] balls;
  return 0;
}
