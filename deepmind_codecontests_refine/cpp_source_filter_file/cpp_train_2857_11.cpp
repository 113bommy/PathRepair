#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma G++ optimize(2)
#pragma GCC optimize(3)
#pragma G++ optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
struct node {
  int id, x;
  bool operator<(const node& a) const { return x < a.x; }
};
struct node2 {
  int id, x;
  bool operator<(const node2& a) const { return x < a.x; }
};
int n, m, f[300005], a[300005 << 1];
long long ans;
multiset<node> T1;
multiset<node2> T2;
bool vis[300005 << 1];
struct FastIO {
  static const int S = 1048576;
  char buf[S], *L, *R;
  int stk[20], Top;
  ~FastIO() { clear(); }
  inline char nc() {
    return L == R && (R = (L = buf) + fread(buf, 1, S, stdin), L == R) ? EOF
                                                                       : *L++;
  }
  inline void clear() {
    fwrite(buf, 1, Top, stdout);
    Top = 0;
  }
  inline void pc(char ch) {
    Top == S && (clear(), 0);
    buf[Top++] = ch;
  }
  inline void endl() { pc('\n'); }
  FastIO& operator>>(char& ch) {
    while (ch = nc(), ch == ' ' || ch == '\n')
      ;
    return *this;
  }
  template <typename T>
  FastIO& operator>>(T& ret) {
    ret = 0;
    int f = 1;
    char ch = nc();
    while (ch < '0' || ch > '9') {
      if (ch == '-') f = -f;
      ch = nc();
    }
    while (ch >= '0' && ch <= '9') {
      ret = ret * 10 + ch - '0';
      ch = nc();
    }
    ret *= f;
    return *this;
  }
  FastIO& operator>>(char* s) {
    int Len = 0;
    char ch = nc();
    while (ch != '\n') {
      *(s + Len) = ch;
      Len++;
      ch = nc();
    }
  }
  template <typename T>
  FastIO& operator<<(T x) {
    if (x < 0) {
      pc('-');
      x = -x;
    }
    do {
      stk[++stk[0]] = x % 10;
      x /= 10;
    } while (x);
    while (stk[0]) pc('0' + stk[stk[0]--]);
    return *this;
  }
  FastIO& operator<<(char ch) {
    pc(ch);
    return *this;
  }
  FastIO& operator<<(string str) {
    int Len = str.size() - 1;
    for (stk[0] = 0; Len >= 0; Len--) stk[++stk[0]] = str[Len];
    while (stk[0]) pc(stk[stk[0]--]);
    return *this;
  }
} fin, fout;
int main() {
  fin >> n >> m;
  for (int i = 0; i < n; ++i)
    fin >> a[i] >> a[i + n], a[i + n] -= a[i], T1.insert(node{i, a[i]}),
        T2.insert(node2{i, a[i + n] + a[i]});
  while (m--) {
    while (!T2.empty() && vis[T2.begin()->id]) T2.erase(T2.begin());
    while (!T1.empty() && vis[T1.begin()->id]) T1.erase(T1.begin());
    if (T2.empty()) {
      int i = T1.begin()->id;
      T1.erase(T1.begin());
      ans += a[i], (i < n) && (T1.insert(node{i + n, a[i + n]}), 0), f[i % n]++,
          vis[i] = 1;
      continue;
    }
    int i = T2.begin()->id, j = T1.begin()->id, num = j;
    T1.erase(T1.begin());
    while (!T1.empty() && vis[T1.begin()->id]) T1.erase(T1.begin());
    int k;
    if (T1.empty())
      k = n * 2;
    else
      k = T1.begin()->id;
    if (a[j] + a[k] >= a[i + n] + a[i])
      num = i, T1.insert(node{j, a[j]}), T2.erase(T2.begin());
    ans += a[num], (num < n) && (T1.insert(node{num + n, a[num + n]}), 0),
        f[num % n]++, vis[num] = 1;
  }
  fout << ans << '\n';
  for (register int i = 0; i < n; i++) fout << f[i];
  return 0;
}
