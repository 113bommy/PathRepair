#include <bits/stdc++.h>
using namespace std;
const double PI =
    3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps(char *x, char *y) {
  char temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
void swapi(int *a, int *b) {
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a == 1 || b == 1) return 1;
  if (a == b) return a;
  if (a > b)
    return gcd(b, a % b);
  else
    return gcd(a, b % a);
}
const long long MOD = 1000000007LL;
long long dp[101][2600];
int l;
string str;
long long calc(int idx, int last) {
  if (idx == l - 1) return 1;
  long long &Res = dp[idx][last];
  if (Res != -1) return Res;
  Res = 0;
  for (int i = 0;; i++) {
    if (str[idx] - 'a' - i >= 0 && str[idx + 1] - 'a' + i <= 25)
      Res = (Res + calc(idx + 1, str[idx] - 'a' + i)) % MOD;
    else
      break;
  }
  for (int i = 1;; i++) {
    if (str[idx] - 'a' + i <= 25 && str[idx + 1] - 'a' - i >= 0)
      Res = (Res + calc(idx + 1, str[idx] - 'a' - i)) % MOD;
    else
      break;
  }
  return Res;
}
int main() {
  int Cases = 1;
  dp[0][0] = 1;
  for (int i = 1; i < 101; i++) {
    for (int j = 0; j <= 25 * 26; j++) {
      for (int k = 0; k < 26; k++) {
        if (j >= k) dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
      }
    }
  }
  for (int Case = 0; Case < Cases; Case++) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> str;
      int S = 0;
      for (int i = 0; i < str.length(); i++) {
        S += str[i] - 'a';
      }
      cout << (dp[str.length()][S] - 1 + MOD) % MOD << endl;
    }
  }
  return 0;
}
