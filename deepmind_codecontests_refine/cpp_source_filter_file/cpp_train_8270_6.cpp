#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)(1e9) + 7;
int s[633 + 1];
int dp[2][400000 + 1];
int a, b;
void readFile() { cin >> a >> b; }
void modd(int &a) {
  if (a >= MOD) a -= MOD;
}
int rez;
void solve() {
  int ant = 0, cr = 1;
  dp[ant][0] = 1;
  dp[ant][1] = 1;
  int sum = 0;
  for (int i = 2; ((i * (i + 1)) >> 1) <= a + b; i++) {
    sum = ((i * (i + 1)) >> 1);
    for (int x = 0; x <= ((i * (i + 1)) >> 1); x++) {
      dp[cr][x] = dp[ant][x];
      if (x >= i) {
        dp[cr][x] += dp[ant][x - i];
        modd(dp[cr][x]);
      }
    }
    swap(cr, ant);
  }
  for (int i = 0; i <= a; i++) {
    if (sum - i <= b) {
      rez += dp[ant][i];
      modd(rez);
    }
  }
}
void printFile() { cout << rez << "\n"; }
int main() {
  readFile();
  solve();
  printFile();
  return 0;
}
