#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -1;
  } while (ch < '0' || ch > '9');
  do {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f * x;
}
int k;
int n;
int a[5010];
int val[5010];
int id[5010];
int p[5010], q[5010];
long long sum;
inline void solve(int l, int r) {
  int k = id[val[l] ^ q[l]];
  if (k == l) return;
  if (k == r) {
    swap(id[p[l]], id[p[k]]);
    swap(p[l], p[k]);
    return;
  } else {
    swap(id[p[l]], id[p[k]]);
    swap(p[l], p[k]);
    swap(q[r], q[k]);
    solve(k, r);
  }
}
int main() {
  k = read();
  n = (1 << k);
  for (int i = 0; i < n; i++)
    a[i] = read(), sum ^= a[i], id[i] = p[i] = q[i] = i, val[i] = 0;
  if (sum) {
    cout << "Fou" << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] ^ val[i]) {
      val[i + 1] = val[i + 1] ^ (val[i] ^ a[i]);
      val[i] = a[i];
      solve(i, i + 1);
    }
  }
  cout << "Shi" << endl;
  for (int i = 0; i < n; i++) cout << p[i] << " ";
  cout << endl;
  for (int i = 0; i < n; i++) cout << q[i] << " ";
  return 0;
}
