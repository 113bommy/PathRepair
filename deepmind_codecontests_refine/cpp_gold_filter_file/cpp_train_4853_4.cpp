#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long a[N], pre[N];
long long ans = -0x3f3f3f3f3f3f3f3f;
int ansi, ansj, ansk, j, k, n;
long long tmp;
void getmax(int l) {
  tmp = 0, j = l;
  long long t = pre[l - 1] - (pre[n] - pre[l - 1]);
  if (t > ans) {
    ans = t;
    ansi = l;
    ansj = l;
    ansk = l;
  }
  for (int i = l; i <= n; i++) {
    if (tmp < 0) {
      tmp = a[i];
      j = i;
    } else {
      tmp += a[i];
    }
    long long t = pre[l - 1] - (pre[n] - pre[l - 1]) + 2 * tmp;
    if (t > ans) {
      ans = t;
      ansi = l;
      ansj = j;
      ansk = i + 1;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pre[i] = pre[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    getmax(i);
  }
  cout << ansi - 1 << " " << ansj - 1 << " " << ansk - 1 << endl;
  return 0;
}
