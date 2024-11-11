#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e5;
map<long long, long long> mala;
long long b[maxn], a[maxn], q, l, m, p = 1, ans = 0;
int main() {
  cin >> b[1] >> q >> l >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    mala[a[i]] = 1;
  }
  if (b[1] > l) {
    cout << 0;
    return 0;
  }
  if (b[1] == 0) {
    if (mala[b[1]] == 1) {
      cout << 0;
    } else {
      cout << "inf";
    }
    return 0;
  }
  if (q == 1) {
    if (mala[b[1]] == 1) {
      cout << 0;
    } else {
      cout << "inf";
    }
    return 0;
  }
  if (q == -1) {
    if (mala[b[1]] && mala[-b[1]]) {
      cout << 0;
    } else
      cout << "inf";
    return 0;
  }
  if (q == 0) {
    if (mala[b[1]] == 0) {
      ans++;
    }
    if (mala[0] == 0) {
      cout << "inf";
    } else {
      cout << ans;
    }
    return 0;
  }
  while (abs(b[p]) <= l) {
    p++;
    b[p] = b[p - 1] * q;
  }
  p--;
  ans = p;
  for (int i = 1; i <= p; i++) {
    if (mala[b[i]] == 1) {
      ans--;
    }
  }
  cout << ans;
}
