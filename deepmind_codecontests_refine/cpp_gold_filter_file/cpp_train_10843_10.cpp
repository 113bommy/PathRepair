#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T gcd(T a, T b) {
  while (b != 0) swap(b, a %= b);
  return a;
}
template <typename T>
inline T lcm(T a, T b) {
  return ((a / gcd(a, b)) * b);
}
void solve() {
  unsigned long long int a, b, m;
  cin >> a >> b >> m;
  if (a == b) {
    cout << 1 << " " << a;
    return;
  }
  bool can = false;
  unsigned long long int k = 2, two = 1;
  for (; k <= 50; k++) {
    if (two * (a + 1) <= b && b <= two * (a + m)) {
      can = true;
      break;
    }
    two = two * 2;
  }
  if (!can) {
    cout << -1;
  } else {
    cout << k << " ";
    unsigned long long int n = (b / two) - a;
    unsigned long long int rem = b % two;
    vector<unsigned long long int> r(k + 1, 0);
    r[k] = n;
    for (unsigned long long int i = k - 1; i >= 2; i--) {
      r[i] = (n + rem % 2);
      rem = rem >> 1;
    }
    cout << a << " ";
    a = a + r[2];
    cout << a << " ";
    for (unsigned long long int i = 3; i <= k; i++) {
      a = 2 * a + r[i] - r[i - 1];
      cout << a << " ";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  unsigned long long int testnum = 1, totalnum = 1;
  cin >> totalnum;
  for (testnum = 1; testnum <= totalnum; ++testnum) {
    solve();
    cout << '\n';
  }
  return 0;
}
