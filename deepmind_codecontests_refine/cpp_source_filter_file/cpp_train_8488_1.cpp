#include <bits/stdc++.h>
using namespace std;
bitset<1000100> vis;
int arr[1000100], n;
int p[1000], cnt, cur[1000100], pre[1000100];
void get_prime() {
  for (int i = 2; i <= 1000; i++)
    if (!vis[i]) {
      p[cnt++] = i;
      for (int j = i * i; j <= 1000100; j += i) vis[j] = true;
    }
}
int s[1000100], cp[1000100], f[1000100], gas[1000100], tot[1000100];
void get_seed() {
  for (int i = 1; i <= n; i++) {
    int x = i;
    s[i] = 1;
    if (!vis[x] && x > sqrt(n)) {
      if (x > n / 2)
        gas[1]++;
      else {
        cp[i] = x;
        f[i] = n / x;
        tot[f[i]]++;
      }
      continue;
    }
    for (int j = 0; j < cnt && p[j] <= sqrt(x); j++) {
      if (x % p[j] == 0) {
        s[i] *= p[j];
        while (x % p[j] == 0) x /= p[j];
      }
    }
    if (x > sqrt(n)) cp[i] = x, f[i] = n / x;
    s[i] *= x;
    gas[s[i]]++;
  }
}
int rp[1000100];
void get_mul() {
  rp[0] = 1;
  for (int i = 1; i <= n; i++) rp[i] = 1ll * rp[i - 1] * i % 1000000007;
}
void finish() {
  puts("0");
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", arr + i);
  get_prime();
  get_seed();
  get_mul();
  for (int i = 1; i <= n; i++) {
    if (!arr[i]) continue;
    if (f[arr[i]] != f[i]) cerr << i << " " << arr[i] << endl, finish();
    if (!f[i]) {
      if (s[i] != s[arr[i]]) finish();
      gas[s[i]]--;
      continue;
    } else {
      if (s[i] > 1) gas[s[i]]--;
      if (pre[cp[arr[i]]] && pre[arr[i]] != cp[i]) finish();
      if (pre[cp[arr[i]]] == 0) {
        pre[cp[arr[i]]] = cp[i];
      }
      if (cur[cp[i]] && cur[cp[i]] != cp[arr[i]]) finish();
      if (cur[cp[i]] == 0) {
        cur[cp[i]] = cp[arr[i]];
        tot[f[i]]--;
      }
    }
  }
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    if (gas[i]) {
      ans = ans * rp[gas[i]] % 1000000007;
    }
    if (tot[i]) {
      ans = ans * rp[tot[i]] % 1000000007;
    }
  }
  cout << ans << endl;
}
