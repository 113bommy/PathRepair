#include <bits/stdc++.h>
using namespace std;
long long largestPower(long long n) {
  long long base = 1, idx = 0;
  while (base * (3ll) <= n) {
    idx++;
    base = base * 3;
  }
  return idx;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    long long n, tempn;
    cin >> n;
    tempn = n;
    int vis[65] = {0};
    memset(vis, 0, sizeof(vis));
    int idx = largestPower(n);
    for (long long i = idx; i >= 0; i--) {
      long long lar = pow(3, i);
      if (pow(3, i) <= n) {
        vis[i] = 1;
        n -= pow(3, i);
      }
    }
    if (n == 0) {
      cout << tempn << "\n";
      continue;
    }
    for (int i = 0; i <= 64; i++) {
      if (vis[i]) {
        vis[i] = 0;
      } else {
        vis[i] = 1;
        break;
      }
    }
    long long m = 0, three = 1;
    for (long long i = 0; i <= 64 && m < tempn; i++) {
      if (vis[i]) {
        m = m + pow((3ll), i);
      }
    }
    cout << m << "\n";
  }
}
