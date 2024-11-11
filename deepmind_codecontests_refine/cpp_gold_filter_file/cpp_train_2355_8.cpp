#include <bits/stdc++.h>
using namespace std;
long long m[111111];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, x;
  cin >> n >> x;
  long long s = 0;
  m[1] = 1 << 19;
  m[2] = 1 << 18;
  s = m[1] ^ m[2];
  for (int i = 3; i < n; i++) {
    m[i] = i;
    s ^= i;
  }
  m[n] = s ^ x;
  if (n == 1) {
    cout << "YES\n" << x;
    return 0;
  } else if (n == 2) {
    if (x == 0) {
      cout << "NO";
      return 0;
    }
    cout << "YES" << endl;
    cout << m[1] << ' ' << (m[1] ^ x);
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 1; i < n + 1; i++) cout << m[i] << ' ';
  return 0;
}
