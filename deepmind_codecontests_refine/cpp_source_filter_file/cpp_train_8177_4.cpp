#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 60;
const double dinf = 1e10;
template <typename T>
inline void scf(T &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) {
  scf(x);
  return scf(y);
}
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) {
  scf(x);
  scf(y);
  return scf(z);
}
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) {
  scf(x);
  scf(y);
  scf(z);
  return scf(w);
}
const int N = 2048;
int n, m;
int u[N * N], v[N * N];
bitset<N + N> a[N];
int main() {
  scf(n, m);
  for (int i = 0; i < (m); i++) {
    scf(u[i], v[i]);
    a[u[i]].set(v[i]);
  }
  for (int i = (1); i <= (n); i++) a[i].set(i + n);
  for (int i = (1); i <= (n); i++) {
    int pivot = -1;
    for (int j = (i); j <= (n); j++)
      if (a[i][j]) {
        pivot = j;
        break;
      }
    swap(a[pivot], a[i]);
    for (int j = (1); j <= (n); j++)
      if (j != i && a[j][i]) a[j] ^= a[i];
  }
  for (int i = 0; i < (m); i++) {
    puts(a[v[i]][u[i] + n] == 1 ? "NO" : "YES");
  }
  return 0;
}
