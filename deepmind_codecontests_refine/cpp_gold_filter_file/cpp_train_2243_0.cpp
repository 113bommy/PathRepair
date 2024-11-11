#include <bits/stdc++.h>
using namespace std;
char CRTBUFF[30000];
struct debugger {
  static void call(const char* it) {}
  template <typename T, typename... aT>
  static void call(const char* it, T a, aT... rest) {
    string b;
    for (; *it && *it != ','; ++it)
      if (*it != ' ') b += *it;
    cout << b << "=" << a << " ";
    call(++it, rest...);
  }
};
long long Fact[1000000 + 100];
long long modPow(long long x, long long e) {
  long long res = 1;
  while (e) {
    if (e & 1) res = (res * x) % 1000003;
    x = (x * x) % 1000003, e >>= 1;
  }
  return res;
}
long long nck(long long n, long long k) {
  long long top = Fact[n];
  long long bot = (Fact[k] * Fact[n - k]) % 1000003;
  return (top * modPow(bot, 1000003 - 2)) % 1000003;
}
void init() {
  Fact[0] = 1;
  for (int i = (1); i < (1000000); i += (1))
    Fact[i] = (Fact[i - 1] * i) % 1000003;
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  init();
  int n, k;
  while (cin >> n >> k) {
    long long ans = 0;
    for (int i = (1); i < (n + 1); i += (1)) {
      ans = (ans + nck(i + k - 1, i)) % 1000003;
    }
    cout << ans << "\n";
  }
  return 0;
}
