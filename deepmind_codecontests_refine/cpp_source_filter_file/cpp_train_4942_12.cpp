#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
inline long long int add(long long int p, long long int q) {
  return p + q >= mod ? p + q - mod : p + q;
}
inline long long int sub(long long int p, long long int q) {
  return p - q < 0 ? p - q + mod : p - q;
}
inline long long int mul(long long int p, long long int q) {
  return p * q % mod;
}
string s, p;
int sl, pl;
int f[(int)1e5 + 5];
bool ok[(int)1e5 + 5];
void fail() {
  f[0] = -1;
  int k = -1;
  for (int i = 1; i < pl; i++) {
    while (k >= 0 && p[k + 1] != p[i]) k = f[k];
    if (p[k + 1] == p[i]) k++;
    f[i] = k;
  }
}
void kmp() {
  fail();
  int k = -1;
  for (int i = 0; i < sl; i++) {
    while (k >= 0 && p[k + 1] != s[i]) k = f[k];
    if (p[k + 1] == s[i]) k++;
    if (k == pl - 1) {
      ok[(i - pl + 1)] = true;
      k = f[k];
    }
  }
}
long long int fromThis[112345];
long long int thisAndRest[112345];
long long int sumThisAndRest[112345];
int main() {
  cin >> s >> p;
  sl = s.length();
  pl = p.length();
  kmp();
  int i = sl;
  while (i >= 0 && ok[i] == false) {
    fromThis[i] = 0;
    thisAndRest[i] = 1;
    sumThisAndRest[i] = add(sumThisAndRest[i + 1], thisAndRest[i]);
    i--;
  }
  long long int neu = 0, last = sl + 1;
  for (; i >= 0; i--) {
    if (ok[i]) {
      fromThis[i] = sumThisAndRest[i + pl];
    } else {
      fromThis[i] = neu;
    }
    thisAndRest[i] = add(thisAndRest[i + 1], fromThis[i]);
    sumThisAndRest[i] = add(sumThisAndRest[i + 1], thisAndRest[i]);
    if (ok[i]) {
      neu = add(neu, sub(fromThis[i], sumThisAndRest[last]));
      last = i + pl;
    }
  }
  long long int ans = thisAndRest[0] - 1;
  cout << ans << "\n";
  return 0;
}
