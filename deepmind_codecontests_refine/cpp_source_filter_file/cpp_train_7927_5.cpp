#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int n, aa[N], bb[N], a[N], v[N], bel[N], d;
void fix(int x, int y) {
  int p = bb[x] ^ v[x], t = bel[p];
  if (t == x) return;
  if (t == y) {
    swap(aa[x], aa[y]);
    swap(bel[aa[x]], bel[aa[y]]);
    return;
  }
  swap(bel[p], bel[a[x]]);
  swap(aa[t], aa[x]);
  swap(bb[t], bb[y]);
  fix(t, y);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  n = 1 << n;
  for (int i = 0; i < n; i++)
    cin >> a[i], d ^= a[i], aa[i] = bb[i] = bel[i] = i;
  if (d) {
    cout << "Fou" << endl;
    return 0;
  }
  cout << "Shi" << endl;
  for (int i = 0; i + 1 < n; i++)
    if (v[i] != a[i]) {
      int x = v[i] ^ a[i];
      v[i] ^= x;
      v[i + 1] ^= x;
      fix(i, i + 1);
    }
  for (int i = 0; i < n; i++) cout << aa[i] << ' ';
  cout << endl;
  for (int i = 0; i < n; i++) cout << bb[i] << ' ';
  return 0;
}
