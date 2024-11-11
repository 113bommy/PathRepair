#include <bits/stdc++.h>
using namespace std;
using namespace std;
int inp;
void sc(long long &x) {
  scanf("%d", &inp);
  x = inp;
}
void sc(long long &x, long long &y) {
  scanf("%d", &inp);
  x = inp;
  scanf("%d", &inp);
  y = inp;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool check(long long A) {
  if (A < 9032) return 1;
  return 0;
}
long long bslrg(long long L, long long R) {
  long long mid, beg = L, en = R;
  while (true) {
    if (en - beg <= 20)
      for (long long i = en; i >= beg; i--)
        if (check(i)) return i;
    mid = (beg + en + 1ll) / 2;
    if (check(mid))
      beg = mid;
    else
      en = mid - 1ll;
  }
  return -1;
}
long long bssml(long long L, long long R) {
  long long mid, beg = L, en = R;
  while (true) {
    if (en - beg <= 20)
      for (long long i = beg; i <= en; i++)
        if (check(i)) return i;
    mid = (beg + en + 1ll) / 2;
    if (check(mid))
      en = mid;
    else
      beg = mid + 1ll;
  }
  return -1;
}
void setbit(int &m, int ind, int val) {
  if (val)
    m = (m | (1 << ind));
  else
    m = (m & ~(1 << ind));
}
bool getbit(int m, int ind) {
  int a = (1 << ind);
  a = (a & m);
  return a;
}
int cntbits(int m) {
  int ret = 0;
  while (m) {
    ret += (m % 2);
    m /= 2;
  }
  return ret;
}
bool smlltr(char c) {
  if (c >= 'a' && c <= 'z') return 1;
  return 0;
}
bool capltr(char c) {
  if (c >= 'A' && c <= 'Z') return 1;
  return 0;
}
const long long MOD = 1e9 + 7;
long long pow_mod(long long a, long long b) {
  if (b == 0) return 1ll;
  if (b % 2) return (a * pow_mod((a * a) % MOD, b / 2)) % MOD;
  return pow_mod((a * a) % MOD, b / 2);
}
long long n, m, k, L, maxi, mini, Q, x, y, a[1000100], sol[1000100],
    bit[1000100];
vector<int> res;
vector<int> computePrefix(string pat) {
  int m = pat.length();
  vector<int> longestPrefix(1000100);
  for (int i = 1, k = 0; i < m; ++i) {
    while (k > 0 && pat[k] != pat[i]) k = longestPrefix[k - 1];
    if (pat[k] == pat[i])
      longestPrefix[i] = ++k;
    else
      longestPrefix[i] = k;
  }
  return longestPrefix;
}
int main() {
  string s;
  cin >> s;
  n = s.length();
  vector<int> v = computePrefix(s);
  if (v[n - 1] == 0) {
    cout << "Just a legend";
    return 0;
  }
  for (int i = 0; i <= n - 2; i++)
    if (v[i] == v[n - 1]) {
      for (int j = 0; j <= v[i] - 1; j++) cout << s[j];
      return 0;
    }
  if (v[v[n - 1]] == 0) {
    cout << "Just a legend";
    return 0;
  }
  for (int j = 0; j <= v[v[n - 1]] - 1; j++) cout << s[j];
  return 0;
}
