#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 1;
const int mod = 1e9 + 7;
bool vis[N];
int pow_mod(long long x, int bit, const int &mod) {
  long long ret = 1;
  for (; bit; bit >>= 1) {
    if (bit & 1) {
      ret = ret * x % mod;
    }
    x = x * x % mod;
  }
  return ret;
}
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  int p, k;
  int answer = 1;
  cin >> p >> k;
  if (k == 0) {
    for (int i = 0; i < p - 1; i++) {
      answer = (long long)answer * p % mod;
    }
    cout << answer << endl;
    return 0;
  }
  for (int i = 0; i < p; i++)
    if (!vis[i]) {
      int j = i * 1LL * k % p;
      int c = 1;
      while (j != i) {
        vis[j] = true;
        j = j * 1LL * k % p;
        c++;
      }
      vis[j] = true;
      if (k <= 1) {
        answer = (long long)answer * p % mod;
      } else if (pow_mod(k, c, p) == 1) {
        answer = (long long)answer * p % mod;
      }
    }
  cout << answer << endl;
  return 0;
}
