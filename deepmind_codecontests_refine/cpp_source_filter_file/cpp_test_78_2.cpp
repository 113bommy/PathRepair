#include <bits/stdc++.h>
using namespace std;
int a[40];
int zui(int a, int b) {
  int t = a % b;
  while (t) {
    a = b;
    b = t;
    t = a % b;
  }
  return b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    memset(a, 0, sizeof a);
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x != 0) flag = 0;
      for (int j = 1; j <= n; j++) {
        int f = x % 2;
        x /= 2;
        if (f) a[j]++;
      }
    }
    if (flag) {
      for (int i = 1; i < n; i++) cout << i << " ";
      cout << n << endl;
      continue;
    }
    int m;
    int j = 1;
    for (int i = 1; i <= 32; i++) {
      if (a[i]) {
        m = a[i];
        j = i;
        break;
      }
    }
    for (j++; j <= 32; j++) {
      if (a[j]) {
        m = zui(m, a[j]);
      }
    }
    for (int i = 1; i < m; i++) {
      if (m % i == 0) cout << i << " ";
    }
    cout << m << endl;
  }
  return 0;
}
