#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 1000005;
inline long long power(long long b, long long e) {
  long long ans = 1;
  while (e > 0) {
    if (e & 1) ans = (ans * b) % MOD;
    b = (b * b) % MOD;
    e >>= 1;
  }
  return ans;
}
int n;
char a[N], b[N];
int freq[26];
long long inv[N], fact[N];
inline long long select() {
  long long ans = fact[n];
  for (int i = 0; i < 26; i++)
    ans = (ans * inv[freq[i] > 0 ? freq[i] : 0]) % MOD;
  return ans;
}
inline long long get(int id) {
  long long ans = 0, aux = select();
  while (++id < 26) {
    if (freq[id] > 0) {
      ans += aux * fact[freq[id]] % MOD * inv[freq[id] - 1] % MOD;
    }
  }
  return ans % MOD;
}
int main() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = power(fact[i], MOD - 2);
  }
  scanf("%s", a);
  scanf("%s", b);
  n = strlen(a);
  for (int i = 0; a[i]; i++) freq[a[i] - 'a']++;
  long long ans = 0;
  for (int i = 0; a[i]; i++) {
    n--;
    ans = (ans + get(a[i] - 'a')) % MOD;
    freq[a[i] - 'a']--;
  }
  n = strlen(a);
  for (int i = 0; a[i]; i++) freq[a[i] - 'a']++;
  for (int i = 0; b[i]; i++) {
    n--;
    ans = (ans - get(b[i] - 'a')) % MOD;
    freq[b[i] - 'a']--;
    if (freq[b[i] - 'a'] < 0) break;
  }
  for (int i = 0; i < 26; i++) {
    if (freq[i]) {
      printf("%lld\n", (ans + MOD) % MOD);
      return 0;
    }
  }
  printf("%lld\n", (ans + MOD - 1) % MOD);
  return 0;
}
