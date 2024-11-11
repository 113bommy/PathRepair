#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long div(vector<int> &a, long long x, vector<int> &b) {
  b.clear();
  long long cur = 0;
  for (int d : a) {
    cur = cur * 10 + d;
    if (cur >= x || !b.empty()) b.push_back(cur / x);
    cur %= x;
  }
  return cur;
}
void convert(vector<int> &a, long long x, vector<int> &b) {
  vector<int> _v;
  vector<int> *pre = &a, *next = &_v;
  b.clear();
  while (!pre->empty()) {
    int rem = div(*pre, x, *next);
    b.push_back(rem);
    swap(pre, next);
  }
}
long long prime, alpha;
int n;
vector<int> v;
void read() {
  string s;
  cin >> s;
  vector<int> a(s.length());
  for (int i = 0; i < s.length(); i++) a[i] = s[i] - '0';
  convert(a, prime, v);
  n = v.size();
}
long long p[2][4000][2][2];
void add(long long &a, long long b) { a = (a + b) % mod; }
long long f(long long x) {
  if (x < prime)
    return 0;
  else
    return (2 * prime - x - 1 + prime - 1) * (x - prime + 1) / 2 % mod;
}
int main() {
  cin >> prime >> alpha;
  read();
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  memset(p, 0, sizeof(p));
  int cur = 0;
  p[cur][0][1][0] = 1;
  for (int i = n; i > 0; i--) {
    int nxt = 1 - cur;
    for (int d = 0; d <= n - i; d++)
      for (int e = 0; e < 2; e++)
        for (int r = 0; r < 2; r++)
          if (p[cur][d][e][r]) {
            for (int nr = 0; nr < 2; nr++) {
              for (int ne = 0; ne <= e; ne++) {
                if (ne) {
                  long long s = r * prime + v[i - 1] - nr;
                  if (s < 0 || s >= 2 * prime - 1) continue;
                  long long ways =
                      (s < prime ? s + 1 : 2 * prime - s - 1) % mod;
                  add(p[nxt][d + r][ne][nr], p[cur][d][e][r] * ways);
                } else if (r) {
                  long long s;
                  if (e) {
                    s = prime + v[i - 1] - nr - 1;
                    if (s < 0) continue;
                  } else {
                    s = prime + prime - 2;
                  }
                  if (nr) {
                    if (s >= prime - 1)
                      add(p[nxt][d + r][ne][nr],
                          (prime + f(s)) % mod * p[cur][d][e][r]);
                  } else {
                    if (s >= prime)
                      add(p[nxt][d + r][ne][nr], f(s) * p[cur][d][e][r]);
                  }
                } else {
                  long long s = e ? v[i - 1] - nr - 1 : prime - 1 - nr;
                  if (s < 0) continue;
                  add(p[nxt][d + r][ne][nr],
                      (s + 1) * (s + 2) / 2 % mod * p[cur][d][e][r]);
                }
              }
            }
            p[cur][d][e][r] = 0;
          }
    cur = nxt;
  }
  long long res = 0;
  for (int e = 0; e < 2; e++)
    for (int x = alpha; x <= n; x++) add(res, p[cur][x][e][0]);
  cout << res << endl;
  return 0;
}
