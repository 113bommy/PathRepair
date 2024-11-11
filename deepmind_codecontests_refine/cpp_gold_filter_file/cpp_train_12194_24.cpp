#include <bits/stdc++.h>
using namespace std;
const int MAX = 7010, maxn = 1e5 + 10;
bitset<MAX> tr0[MAX], tr1[MAX], a[maxn], tmp;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i < MAX; i++) {
    for (int j = i; j < MAX; j += i) {
      tr0[j][i] = 1;
    }
  }
  for (int i = MAX - 1; i >= 1; i--) {
    for (int j = i; j < MAX; j += i) tr1[i] ^= tr1[j];
    tr1[i][i] = 1;
  }
  int n, q;
  cin >> n >> q;
  while (q--) {
    int task;
    cin >> task;
    if (task == 1) {
      int x, v;
      cin >> x >> v;
      a[--x] = tr0[v];
    }
    if (task == 2) {
      int x, y, z;
      cin >> x >> y >> z;
      a[--x] = a[--y] ^ a[--z];
    }
    if (task == 3) {
      int x, y, z;
      cin >> x >> y >> z;
      a[--x] = a[--y] & a[--z];
    }
    if (task == 4) {
      int x, v;
      cin >> x >> v;
      tmp = a[--x] & tr1[v];
      cout << tmp.count() % 2;
    }
  }
  cout << endl;
  return 0;
}
