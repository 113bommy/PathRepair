#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long powmod(long long a, long long b, long long MOD) {
  if (a == 0ll) {
    return 0ll;
  }
  a %= MOD;
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans * a % MOD;
    }
    a = a * a % MOD;
    b >>= 1;
  }
  return ans;
}
void Pv(const vector<int> &V) {
  int Len = int(V.size());
  for (int i = 0; i < Len; ++i) {
    printf("%d", V[i]);
    if (i != Len - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}
void Pvl(const vector<long long> &V) {
  int Len = int(V.size());
  for (int i = 0; i < Len; ++i) {
    printf("%lld", V[i]);
    if (i != Len - 1) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
}
inline long long readll() {
  long long tmp = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar();
  return tmp * fh;
}
inline int readint() {
  int tmp = 0, fh = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') fh = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') tmp = tmp * 10 + c - 48, c = getchar();
  return tmp * fh;
}
const int maxn = 1000010;
const int inf = 0x3f3f3f3f;
set<int> l, r;
set<int> vis;
int n, m;
int a[maxn];
std::vector<int> v;
int main() {
  long long ans = 0ll;
  n = readint();
  m = readint();
  for (int i = 1; i <= n; i++) {
    a[i] = readint();
    vis.insert(a[i]);
    l.insert(a[i]);
    r.insert(a[i]);
  }
  int cnt = 1;
  set<int>::iterator it;
  while (vis.size() - n < m) {
    for (auto x : l) {
      if (vis.count(x - cnt) == 1) {
        v.push_back(x);
      } else {
        vis.insert(x - cnt);
        ans += cnt;
        if (vis.size() - n == m) {
          break;
        }
      }
    }
    for (auto x : v) {
      it = l.lower_bound(x);
      l.erase(it);
    }
    v.clear();
    if (vis.size() - n == m) {
      break;
    }
    for (auto x : r) {
      if (vis.count(x + cnt) == 1) {
        v.push_back(x);
      } else {
        vis.insert(x + cnt);
        ans += cnt;
        if (vis.size() - n == m) {
          break;
        }
      }
    }
    for (auto x : v) {
      it = r.lower_bound(x);
      r.erase(it);
    }
    v.clear();
    cnt++;
    if (vis.size() - n == m) {
      break;
    }
  }
  printf("%lld\n", ans);
  for (int i = 1; i <= n; i++) {
    it = vis.lower_bound(a[i]);
    vis.erase(it);
  }
  for (auto x : vis) {
    printf("%d ", x);
  }
  return 0;
}
