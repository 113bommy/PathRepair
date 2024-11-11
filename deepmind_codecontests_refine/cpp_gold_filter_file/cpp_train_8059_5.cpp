#include <bits/stdc++.h>
using namespace std;
int c[100000];
int o[100000];
int io[100000];
int main() {
  int n, w, k;
  char t;
  cin >> n >> k >> w;
  for (int i = 0; i < n; i++) {
    cin >> t;
    if (t == '1')
      c[i] = 1;
    else
      c[i] = 0;
  }
  for (int s = 0; s < k; s++) {
    io[s] = c[s];
    for (int a = s + k; a < n; a += k) {
      io[a] = io[a - k] + c[a];
    }
  }
  o[0] = c[0];
  for (int i = 1; i < n; i++) {
    o[i] = o[i - 1] + c[i];
  }
  int l, r;
  int nio, no;
  int d;
  for (int i = 0; i < w; i++) {
    cin >> l >> r;
    r--;
    l--;
    no = o[r] - ((l == 0) ? 0 : o[l - 1]);
    nio = io[r] - ((l == 0) ? 0 : io[l - 1]);
    d = ((r - l + 1) / k) - nio;
    d += no - nio;
    cout << d << endl;
  }
}
