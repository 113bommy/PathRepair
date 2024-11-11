#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <class T>
T gcd(T a, T b) {
  return a ? gcd(b % a, a) : b;
}
template <class T>
T sqr(T a) {
  return a * a;
}
template <class T>
T sgn(T a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
const int N = 2e5 + 10;
const int inf = 1e9 + 10;
const int mod = 1e9 + 7;
int n;
int m;
int main() {
  cin >> n;
  if (n % 4 == 0) {
    cout << 0 << endl;
    cout << n / 2 << " ";
    for (int i = 0; i < n / 2; i += 2) printf("%d %d ", i + 1, n - i);
    return 0;
  }
  if (n % 4 == 2) {
    cout << 1 << endl;
    cout << n / 2 << " ";
    for (int i = 0; i < n / 2 - 1; i += 2) printf("%d %d ", i + 1, n - i);
    cout << n / 2 << endl;
    return 0;
  }
  if (n % 4 == 3) {
    cout << 0 << endl;
    cout << n / 2 << " " << 3 << " ";
    int t = 0;
    for (int i = 4; i <= n; i += 2)
      if (t == 0) {
        cout << i + 1 << " ";
        t = 1;
      } else {
        cout << i << " ";
        t = 0;
      }
    return 0;
  }
  if (n == 1) {
    cout << 1 << endl << "1 1" << endl;
    return 0;
  }
  cout << 1 << endl;
  int tt = n;
  n -= 2;
  cout << n / 2 << " " << 3 << " ";
  int t = 0;
  for (int i = 4; i < n; i += 2)
    if (t == 0) {
      cout << i + 1 << " ";
      t = 1;
    } else {
      cout << i << " ";
      t = 0;
    }
  cout << tt;
  return 0;
}
