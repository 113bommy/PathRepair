#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int mod = 1000000007;
const double pi = acos(-1);
inline void gn(long long& x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
inline void gn(int& x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(unsigned long long& x) {
  long long t;
  gn(t);
  x = t;
}
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
long long powmod(long long a, long long x, long long mod) {
  long long t = 1ll;
  while (x) {
    if (x & 1) t = t * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return t;
}
const int maxn = 155555;
vector<int> pos;
int a[maxn];
int n;
set<pair<int, int> > ans;
bool check(int i) {
  if (i < 1 || i >= n) return true;
  if (i & 1)
    return a[i] < a[i + 1];
  else
    return a[i] > a[i + 1];
}
bool solve(int x, int y) {
  for (int i = 0; i < pos.size(); ++i) {
    if (!check(pos[i])) return false;
    if (!check(pos[i] + 1)) return false;
    if (!check(pos[i] - 1)) return false;
    if (!check(pos[i] + 2)) return false;
    if (!check(pos[i] - 2)) return false;
  }
  for (int i = 1; i < 5; ++i) {
    if (!check(x + i)) return false;
    if (!check(x - i)) return false;
  }
  for (int i = 1; i < 5; ++i) {
    if (!check(y + i)) return false;
    if (!check(y - i)) return false;
  }
  return true;
}
int main() {
  gn(n);
  for (int i = (1); i <= (n); i++) gn(a[i]);
  for (int i = (1); i <= (n); i++)
    if (!check(i)) pos.push_back(i);
  if (pos.size() > 6) return 0 * printf("0\n");
  for (int i = 0; i < pos.size(); ++i) {
    for (int j = 1; j <= n; ++j) {
      int aa = j, bb = pos[i];
      if (aa == bb) continue;
      swap(a[aa], a[bb]);
      if (solve(aa, bb))
        ans.insert(make_pair(((aa) < (bb) ? (aa) : (bb)),
                             ((aa) > (bb) ? (aa) : (bb))));
      swap(a[aa], a[bb]);
    }
  }
  for (int i = 0; i < pos.size(); ++i) {
    for (int j = 1; j <= n; ++j) {
      int aa = j, bb = pos[i] + 1;
      if (bb > n) continue;
      if (aa == bb) continue;
      swap(a[aa], a[bb]);
      if (solve(aa, bb))
        ans.insert(make_pair(((aa) < (bb) ? (aa) : (bb)),
                             ((aa) > (bb) ? (aa) : (bb))));
      swap(a[aa], a[bb]);
    }
  }
  for (int i = 0; i < pos.size(); ++i) {
    for (int j = 1; j <= n; ++j) {
      int aa = j, bb = pos[i] - 1;
      if (bb < 1) continue;
      if (aa == bb) continue;
      swap(a[aa], a[bb]);
      if (solve(aa, bb))
        ans.insert(make_pair(((aa) < (bb) ? (aa) : (bb)),
                             ((aa) > (bb) ? (aa) : (bb))));
      swap(a[aa], a[bb]);
    }
  }
  printf("%d\n", (int)ans.size());
  return 0;
}
