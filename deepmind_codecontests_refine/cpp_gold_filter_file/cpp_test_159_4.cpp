#include <bits/stdc++.h>
using namespace std;
mt19937_64 rnd(time(0));
int n, f[1000005], lst[1000005];
unsigned long long num[1000005], p[1000005];
bool out[1000005];
void print() {
  int cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!out[i]) cnt++;
  cout << cnt << '\n';
  for (int i = 1; i <= n; i++)
    if (!out[i]) cout << i << ' ';
  exit(0);
}
unordered_map<unsigned long long, int> mp;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) f[i] = 1;
  lst[1] = 1;
  for (int i = 2; i <= n; i++)
    if (f[i]) {
      for (int j = i; j <= n; j += i) lst[j] = i, f[j] = 0;
      num[i] = rnd();
    }
  for (int i = 1; i <= n; i++) {
    if (!num[i]) {
      int x = i;
      while (x != 1) {
        num[i] ^= num[lst[x]];
        x /= lst[x];
      }
    }
    p[i] = p[i - 1] ^ num[i];
  }
  unsigned long long now = 0;
  for (int i = 1; i <= n; i++) now = now ^ p[i];
  if (!now) print();
  for (int i = 1; i <= n; i++)
    if (now == p[i]) {
      out[i] = 1;
      print();
    }
  for (int i = 1; i <= n; i++) mp[p[i]] = i;
  for (int i = 1; i <= n; i++)
    if (mp.count(now ^ p[i])) {
      out[mp[now ^ p[i]]] = 1;
      out[i] = 1;
      print();
    }
  out[n / 2] = 1;
  out[n] = 1;
  out[2] = 1;
  print();
  return 0;
}
