#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rread(T& num) {
  num = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
  num *= f;
}
inline int getgcd(int x, int y) {
  if (!x) return y;
  return getgcd(y % x, x);
}
inline long long getlcm(int x, int y) {
  return (long long)x / getgcd(x, y) * y;
}
inline long long getgcd(long long x, long long y) {
  if (!x) return y;
  return getgcd(y % x, x);
}
inline long long getlcm(long long x, long long y) {
  return x / getgcd(x, y) * y;
}
inline int power(int x, int k, int p) {
  int res = 1;
  for (; k; k >>= 1, x = (long long)x * x % p)
    if (k & 1) res = (long long)res * x % p;
  return res;
}
const int maxn = 10005;
int n, a[maxn], b[maxn];
int base[32], base2[32], pos[32], pos2[32], bin[32], arc[maxn];
vector<pair<int, int> > v1, v2, v3;
int main() {
  bin[0] = 1;
  for (int(i) = (1); (i) <= (29); (i)++) bin[i] = bin[i - 1] << 1;
  rread(n);
  for (int(i) = (1); (i) <= (n); (i)++) {
    rread(a[i]);
    int now = a[i];
    for (int(k) = (29); (k) >= (0); (k)--) {
      if ((now ^ base[k]) < now)
        v1.push_back(make_pair(i, pos[k])), now ^= base[k];
      if (now >= bin[k]) {
        base[k] = now;
        pos[k] = i;
        break;
      }
    }
  }
  for (int(i) = (1); (i) <= (n); (i)++) {
    rread(b[i]);
    int now = b[i];
    for (int(k) = (29); (k) >= (0); (k)--) now = min(now, now ^ base[k]);
    if (now) return puts("-1"), 0;
    now = b[i];
    for (int(k) = (29); (k) >= (0); (k)--) {
      if ((now ^ base2[k]) < now)
        v2.push_back(make_pair(i, pos2[k])), now ^= base2[k];
      if (now >= bin[k]) {
        base2[k] = now;
        pos2[k] = i;
        break;
      }
    }
  }
  for (int(k) = (29); (k) >= (0); (k)--)
    if (base[k]) {
      if (!base2[k]) {
        v3.push_back(make_pair(pos[k], pos[k]));
        continue;
      }
      int now = base[k] ^ base2[k];
      for (int(k2) = (k - 1); (k2) >= (0); (k2)--)
        if ((now ^ base[k2]) < now)
          v3.push_back(make_pair(pos[k], pos[k2])), now ^= base[k2];
    }
  for (int(i) = (1); (i) <= (n); (i)++) arc[i] = -1;
  for (int(i) = (0); (i) <= (29); (i)++)
    if (base[i]) arc[pos[i]] = i;
  for (int(k) = (29); (k) >= (0); (k)--)
    if (base[k] && base2[k]) {
      int posi = 0;
      for (int(i) = (1); (i) <= (n); (i)++)
        if (arc[i] == k) {
          posi = i;
          break;
        }
      if (posi == pos2[k]) continue;
      v3.push_back(make_pair(posi, pos2[k]));
      v3.push_back(make_pair(pos2[k], posi));
      v3.push_back(make_pair(posi, pos2[k]));
      swap(arc[pos2[k]], arc[posi]);
    }
  printf("%d\n", v1.size() + v2.size() + v3.size());
  for (int(i) = (0); (i) < (v1.size()); (i)++)
    printf("%d %d\n", v1[i].first, v1[i].second);
  for (int(i) = (0); (i) < (v3.size()); (i)++)
    printf("%d %d\n", v3[i].first, v3[i].second);
  for (int(i) = (v2.size()); (i) > (0); (i)--)
    printf("%d %d\n", v2[i].first, v2[i].second);
  return 0;
}
