#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, k, s, a[MAXN], v[MAXN], p[MAXN], q[MAXN], pos[MAXN];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
void fix(int i, int j) {
  int t = pos[v[i] ^ q[i]];
  if (t == i) return;
  if (t == j) {
    swap(p[i], p[j]), v[i] = p[i] ^ q[i];
    swap(pos[p[i]], pos[p[j]]);
    return v[j] = p[j] ^ q[j], void();
  }
  swap(p[t], p[i]), swap(q[t], q[j]);
  swap(pos[p[t]], pos[p[i]]), fix(t, j);
}
int main() {
  k = read(), n = 1 << k;
  for (int i = 0; i < n; i++) s ^= (a[i] = read());
  if (s) puts("Fou"), exit(0);
  puts("Shi");
  for (int i = 0; i < n; i++) p[i] = q[i] = pos[i] = i;
  for (int i = 0; i < n - 1; i++) {
    v[n] = a[i] ^ v[i], v[i] ^= v[n], v[i + 1] ^= v[n];
    fix(i, i + 1);
  }
  for (int i = 0; i < n; i++) printf("%d%c", p[i], " \n"[i == n - 1]);
  for (int i = 0; i < n; i++) printf("%d%c", q[i], " \n"[i == n - 1]);
  return 0;
}
