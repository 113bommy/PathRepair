#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int tree[10][300000];
int n;
void inc(int x, int tree[]) {
  while (x <= n) {
    tree[x]++;
    x += (x & -x);
  }
}
void dec(int x, int tree[]) {
  while (x <= n) {
    tree[x]--;
    x += (x & -x);
  }
}
int get(int x, int tree[]) {
  int ret = 0;
  while (x) {
    ret += tree[x];
    x -= (x & -x);
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    x++;
    a[i] += x - 1 - get(x, tree[0]);
    inc(x, tree[0]);
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    x++;
    a[i] += x - 1 - get(x, tree[1]);
    inc(x, tree[1]);
  }
  for (int i = n; i >= 1; i--) {
    a[i - 1] += a[i] / (n + 1 - i);
    a[i - 1] %= (n + 1 - i);
  }
  for (int i = 1; i <= n; i++) {
    inc(i, tree[2]);
  }
  for (int i = 1; i <= n; i++) {
    int mn = a[i], hi = n;
    while (mn + 1 < hi) {
      int md = (mn + hi) / 2;
      if (get(md, tree[2]) < a[i] + 1) {
        mn = md;
      } else
        hi = md;
    }
    cout << hi - 1 << " ";
    dec(hi, tree[2]);
  }
  cout << endl;
}
