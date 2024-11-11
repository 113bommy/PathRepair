#include <bits/stdc++.h>
using namespace std;
int mod(int a, int m) {
  if (a < 0) {
    a += m;
  }
  return a % m;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  if (a == b) {
    cout << 0;
    return 0;
  }
  int dAns = m + 1;
  for (int i = 0; i < n; ++i) {
    int distance = mod(a[i] - b[0], m);
    vector<int> nw(a);
    for (int j = 0; j < n; ++j) {
      nw[j] += distance;
      nw[j] %= m;
    }
    int ai, mn = m + 1;
    for (int j = 0; j < n; ++j) {
      if (nw[j] < mn) {
        mn = nw[j];
        ai = j;
      }
    }
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      ok &= nw[(ai + j) % n] == b[j];
    }
    if (ok && distance < dAns) {
      dAns = distance;
    }
  }
  cout << dAns;
}
