#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
template <typename T>
void in(T &x) {
  x = 0;
  bool neg = 0;
  register T c = getchar();
  if (c == '-') neg = 1, c = getchar();
  while ((c < 48) || (c > 57)) c = getchar();
  for (; c < 48 || c > 57; c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  if (neg) x *= -1;
}
template <typename T>
void ou(T n) {
  bool neg = 0;
  if (n < 0) n *= -1, neg = 1;
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + '0';
    n /= 10;
  } while (n);
  --i;
  if (neg) putchar('-');
  while (i >= 0) putchar(snum[i--]);
  putchar(' ');
}
vector<int> fa;
int mul(int a, int b) {
  long long res =
      ((a % (int)1000000007) * 1ll * (b % (int)1000000007)) % (int)1000000007;
  return res;
}
int mad(int a, int b) {
  long long res =
      ((a % (int)1000000007 + b % (int)1000000007) % (int)1000000007);
  return res;
}
int power(int x, int y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
int inv(int x) { return power(x, (int)1000000007 - 2); }
void fact() {
  fa.push_back(1);
  for (int i = 1; i < (int)3e5 + 5; i++) fa.push_back(mul(fa.back(), i));
}
int comb(int n, int r) {
  if (r > n) return 0;
  long long res = mul(fa[n], inv(mul(fa[n - r], fa[r])));
  return res;
}
void pv(vector<int> v, int a, int sz) {
  for (int i = a; i < (int)sz; i++) ou(v[i]);
  cout << "\n";
}
void rpv(vector<int> v, int sz, int a) {
  for (int i = sz; i >= a; --i) ou(v[i]);
  cout << "\n";
}
void pa(int z[], int a, int sz) {
  for (int i = a; i < (int)sz; i++) ou(z[i]);
  cout << "\n";
}
void rpa(int z[], int a, int sz) {
  for (int i = a; i >= sz; --i) ou(z[i]);
  cout << "\n";
}
int main() {
  int n, k;
  in(n), in(k);
  string s;
  cin >> s;
  bool flag = false;
  if (k > n) {
    cout << n << "\n";
    cout << s << "\n";
    return 0;
  }
  int mn1 = INT_MAX, mn2 = INT_MAX;
  for (int i = 0; i < (int)k; i++) {
    if (flag) break;
    int pos = i + k;
    while (pos < n && !flag) {
      if (s[pos] > s[i])
        mn1 = min(mn1, pos);
      else if (s[pos] < s[i])
        mn2 = min(mn2, pos);
      pos += k;
    }
  }
  if (mn1 < mn2)
    flag = true;
  else
    flag = false;
  if (flag) {
    int r = 1;
    while (k - r >= 0 && s[k - r] == '9') r++;
    vector<char> ans;
    if (r > k) {
      ans.resize(n + 1);
      ans[0] = '1';
      for (int i = 1; i < (int)k; i++) ans[i] = '0';
      r = k;
      for (int i = 0; i < (int)k; i++) {
        int pos = i + k;
        while (pos <= n) ans[pos] = ans[pos - k], pos += k;
      }
    } else {
      ans.resize(n);
      for (int i = 0; i < (int)k - r; i++) ans[i] = s[i];
      ans[k - r] = s[k - r] + 1;
      for (int i = k - r + 1; i < (int)k; i++) ans[i] = '0';
      for (int i = 0; i < (int)k; i++) {
        int pos = i + k;
        while (pos < n) ans[pos] = ans[pos - k], pos += k;
      }
    }
    cout << ans.size() << "\n";
    for (auto &i : ans) cout << i;
    cout << "\n";
  } else {
    for (int i = 0; i < (int)k; i++) {
      int pos = i + k;
      while (pos < n) s[pos] = s[pos - k], pos += k;
    }
    cout << n << "\n";
    cout << s << "\n";
  }
}
