#include <bits/stdc++.h>
using namespace std;
int a[1000000], ind = 0;
int h[25], w[25], r[25], h1[25], w1[25], r1[25], st[25];
bool u1[5], u2[5];
bool good[33554432];
int main() {
  int n, k, t;
  cin >> n >> k >> t;
  for (int i = 0; i < k; i++) {
    cin >> h1[i] >> w1[i] >> r1[i];
    h1[i]--;
    w1[i]--;
    st[i] = i;
  }
  random_shuffle(st, st + k);
  for (int i = 0; i < k; i++) {
    h[i] = h1[st[i]];
    w[i] = w1[st[i]];
    r[i] = r1[st[i]];
  }
  good[0] = 1;
  int mask = 1;
  for (int i = 0; i < (1 << k); i++) {
    if ((mask << 1) <= i) mask = (mask << 1);
    if (i > 0 && !good[i - mask]) continue;
    for (int j = 0; j < n; j++) u1[j] = u2[j] = 0;
    bool OK = 1;
    int x = i, cur = 0;
    for (int j = 0; x > 0; j++) {
      if (x & 1)
        if (u1[h[j]] || u2[w[j]]) {
          OK = 0;
          break;
        } else {
          u1[h[j]] = u2[w[j]] = 1;
          cur += r[j];
        }
      x = (x >> 1);
    }
    if (OK) {
      a[ind] = cur;
      ind++;
    }
    good[i] = OK;
  }
  sort(a, a + ind);
  cout << a[t - 1];
}
