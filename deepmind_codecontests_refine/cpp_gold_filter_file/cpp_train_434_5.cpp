#include <bits/stdc++.h>
using namespace std;
template <typename T>
T MAX(T a, T b) {
  return (a > b) ? a : b;
}
template <typename T>
T MIN(T a, T b) {
  return (a < b) ? a : b;
}
template <typename T>
void UMAX(T &a, T b) {
  a = (a > b ? a : b);
}
template <typename T>
void UMIN(T &a, T b) {
  a = (a < b ? a : b);
}
int readint() {
  char c = getchar();
  int ret = 0;
  while (!(c >= '0' && c <= '9')) c = getchar();
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret;
}
void putint(int v) {
  if (!v) {
    putchar('0');
    return;
  }
  if (v >= 10) putint(v / 10);
  putchar('0' + (v % 10));
}
int n;
map<int, int> mp;
int powM(int V, int T) {
  int R = 1;
  while (T) {
    if (T & 1) R = (long long)R * (long long)V % 998244353ll;
    T >>= 1;
    V = (long long)V * (long long)V % 998244353ll;
  }
  return R;
}
void ntt(vector<int> &a, int L, bool r) {
  int i, j = L / 2, k;
  for (i = 1; i < L; ++i) {
    if (i < j) swap(a[i], a[j]);
    for (k = (L >> 1); k & j; k >>= 1) j ^= k;
    j ^= k;
  }
  for (i = 2; i <= L; i <<= 1) {
    int cl = (i >> 1);
    int w = powM(3ll, (998244353ll - 1) / i);
    if (r) w = powM(w, 998244353ll - 2);
    for (j = 0; j < L; j += i) {
      int cur = 1;
      for (k = 0; k < cl; ++k) {
        int &T1 = a[j + k], &T2 = a[j + cl + k];
        int v1 = T1, v2 = (long long)T2 * (long long)cur % 998244353ll;
        T1 = v1 + v2;
        if (T1 >= 998244353ll) T1 -= 998244353ll;
        T2 = v1 - v2;
        if (T2 < 0ll) T2 += 998244353ll;
        cur = (long long)cur * (long long)w % 998244353ll;
      }
    }
  }
}
vector<int> convo(vector<int> a, vector<int> b) {
  int len = (int)a.size() + (int)b.size() + 1, i, j, k;
  vector<int> ret;
  int L = 2;
  while (L < len) L <<= 1;
  a.resize(L, 0);
  b.resize(L, 0);
  ntt(a, L, 0);
  ntt(b, L, 0);
  ret.resize(L);
  for (i = 0; i < L; ++i) {
    ret[i] = (long long)a[i] * (long long)b[i] % 998244353ll;
  }
  ntt(ret, L, 1);
  ret.resize(len);
  while (!(ret.back())) ret.pop_back();
  for (i = 0; i < (int)ret.size(); ++i) {
    ret[i] =
        (long long)ret[i] * (long long)powM(L, 998244353ll - 2) % 998244353ll;
  }
  return ret;
}
vector<int> mtps[200005];
vector<int> calc(int l, int r) {
  if (l == r) return mtps[l];
  int M = (l + r) / 2;
  return convo(calc(l, M), calc(M + 1, r));
}
int main() {
  int i, j, k;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &k);
    ++mp[k];
  }
  map<int, int>::iterator it;
  int cnt = 0;
  for (it = mp.begin(); it != mp.end(); ++it) {
    int S = it->second;
    mtps[cnt].resize(S + 1);
    for (i = 0; i <= S; ++i) mtps[cnt][i] = 1;
    ++cnt;
  }
  vector<int> res = calc(0, cnt - 1);
  printf("%d\n", res[n / 2]);
  return 0;
}
