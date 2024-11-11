#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 12;
int n, a[N], p[N], q[N], r[N];
void fix(int i, int j) {
  int w = a[i] ^ q[i], pt = r[w];
  if (pt == i) return;
  if (pt == j) {
    swap(r[p[i]], r[p[j]]);
    swap(p[i], p[j]);
    return;
  }
  swap(p[i], p[pt]);
  swap(r[p[i]], r[p[pt]]);
  swap(q[j], q[pt]), fix(pt, j);
}
int main() {
  cin >> n;
  n <<= 1;
  int s = 0;
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]), s ^= a[i], r[i] = p[i] = q[i] = i;
  if (s) return puts("Fou"), 0;
  for (int i = 0; i + 1 < n; i++)
    if (p[i] ^ q[i] ^ a[i]) fix(i, i + 1);
  puts("Shi");
  for (int i = 0; i < n; i++) cout << p[i] << " ";
  puts("");
  for (int i = 0; i < n; i++) cout << q[i] << " ";
  puts("");
  return 0;
}
