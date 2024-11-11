#include <bits/stdc++.h>
using namespace std;
int q[200005];
int ans[200005];
int main() {
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  int i;
  for (i = 1; i <= n; i++) {
    char qw;
    cin >> qw;
    q[i] = qw - '0';
  }
  for (; i < 200004; i++) {
    q[i] = 9;
  }
  for (i = 1; i <= n; i++) {
    int t = 0;
    int j;
    if (a == 0) break;
    for (j = 0; j < b; j++) {
      if (q[i + j] == 0)
        continue;
      else {
        t = 1;
        break;
      }
    }
    if (t == 0) {
      for (j = 0; j < b; j++) {
        q[i + j] = 2;
      }
      i = i + j - 2;
      a--;
    }
  }
  int m = 0;
  for (i = n; i >= 1; i--) {
    int t = 0;
    int j;
    for (j = 0; j < b; j++) {
      if (q[i - j] == 0)
        continue;
      else if (q[i - j] == 2) {
        t = 2;
        break;
      } else {
        t = 1;
        break;
      }
    }
    if (t == 0) {
      ans[m++] = i - j + 1;
      i = i - b + 1;
    }
    if (t == 2) {
      ans[m++] = i - j;
      break;
    }
  }
  cout << m << endl;
  for (i = 0; i < m; i++) {
    cout << ans[i] << " ";
  }
}
