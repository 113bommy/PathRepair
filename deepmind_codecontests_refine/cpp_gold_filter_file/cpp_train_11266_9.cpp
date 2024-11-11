#include <bits/stdc++.h>
template <class T>
int gmax(T &a, T b) {
  if (b > a) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
int gmin(T &a, T b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
using namespace std;
const int INF = 0x3f3f3f3f;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
const int MAXN = 2e5 + 5;
int P[MAXN], A[MAXN], id[MAXN];
const long long lazyDefault = 0;
long long minn[MAXN << 2];
long long lazy[MAXN << 2];
void pushUp(int rt) { minn[rt] = min(minn[rt << 1], minn[rt << 1 | 1]); }
void pushDown(int rt, int l, int r) {
  if (lazy[rt] != lazyDefault) {
    minn[rt << 1] += lazy[rt];
    minn[rt << 1 | 1] += lazy[rt];
    lazy[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt];
    lazy[rt] = lazyDefault;
  }
}
void Build(vector<long long> &vc, int l, int r, int rt) {
  lazy[rt] = lazyDefault;
  if (l == r) {
    minn[rt] = vc[l];
    return;
  }
  int m = (l + r) >> 1;
  Build(vc, l, m, rt << 1);
  Build(vc, m + 1, r, rt << 1 | 1);
  pushUp(rt);
}
void Update(int L, int R, long long c, int l, int r, int rt) {
  if (L <= l && r <= R) {
    minn[rt] += c;
    lazy[rt] += c;
    return;
  }
  pushDown(rt, l, r);
  int m = (l + r) >> 1;
  if (L <= m) Update(L, R, c, l, m, rt << 1);
  if (R > m) Update(L, R, c, m + 1, r, rt << 1 | 1);
  pushUp(rt);
}
void debugTree(int l, int r, int rt) {
  printf("%d %d %lld\n", l, r, minn[rt]);
  if (l == r) return;
  pushDown(rt, l, r);
  int m = (l + r) >> 1;
  debugTree(l, m, rt << 1);
  debugTree(m + 1, r, rt << 1 | 1);
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &P[i]);
      id[P[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &A[i]);
    }
    vector<long long> vc;
    long long sum = 0;
    vc.push_back(sum);
    for (int i = 1; i <= n; ++i) {
      sum += A[id[i]];
      vc.push_back(sum);
    }
    Build(vc, 0, n, 1);
    long long ans = 1e18;
    for (int i = 1; i < n; ++i) {
      Update(0, P[i] - 1, A[i], 0, n, 1);
      Update(P[i], n, -A[i], 0, n, 1);
      ans = min(ans, minn[1]);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
