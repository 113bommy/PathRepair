#include <bits/stdc++.h>
using namespace std;
template <class T>
void chkmax(T &a, T b) {
  if (a < b) a = b;
}
template <class T>
void chkmin(T &a, T b) {
  if (a > b) a = b;
}
const int p = 1e9 + 7;
int fac[1000010], rfac[1000010], inv[1000010];
void prepare() {
  fac[0] = rfac[0] = fac[1] = rfac[1] = inv[1] = 1;
  for (int i = 2; i < 1000010; i++) {
    fac[i] = (1ll * fac[i - 1] * i) % p;
    inv[i] = p - (1ll * inv[p % i] * (p / i)) % p;
    rfac[i] = (1ll * rfac[i - 1] * inv[i]) % p;
  }
}
int d[26], e[26];
int func(int *d) {
  int s = 0;
  for (int i = 0; i < 26; i++) s += d[i];
  int tmp = fac[s - 1];
  for (int i = 0; i < 26; i++) tmp = (1ll * tmp * rfac[d[i]]) % p;
  return tmp;
}
char a[1000010], b[1000010];
int ans;
int main() {
  prepare();
  gets(a);
  gets(b);
  int n = strlen(a);
  int s = 0;
  while (a[s] == b[s] && s < n) s++;
  for (int i = s; i < n; i++) d[a[i] - 'a']++;
  for (int i = 0; i < 26; i++) e[i] = d[i];
  for (int i = s; i < n - 1; i++) {
    d[a[i] - 'a']--;
    int tmp = func(d);
    for (int j = a[i + 1] - 'a' + 1; j < 26; j++) {
      if (d[j]) {
        ans += (1ll * tmp * d[j]) % p;
        ans %= p;
      }
    }
  }
  for (int i = 0; i < 26; i++) d[i] = e[i];
  if (s < n) {
    int tp = func(d);
    for (int i = a[s] - 'a' + 1; i < b[s] - 'a'; i++) {
      if (d[i]) {
        ans += (1ll * tp * d[i]) % p;
        ans %= p;
      }
    }
  }
  for (int i = s; i < n - 1; i++) {
    if (!e[b[i] - 'a']) break;
    e[b[i] - 'a']--;
    int tmp = func(e);
    for (int j = 0; j < b[i + 1] - 'a'; j++) {
      if (e[j]) {
        ans += (1ll * tmp * e[j]) % p;
        ans %= p;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
