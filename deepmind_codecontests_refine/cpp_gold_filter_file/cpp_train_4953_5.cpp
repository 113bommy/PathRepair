#include <bits/stdc++.h>
using namespace std;
void addmod(int &a, long long b) {
  a = (a + b);
  if (a >= 1000000007) a -= 1000000007;
}
void mulmod(int &a, long long b) { a = (a * b) % 1000000007; }
template <class T>
bool domin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
bool domax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int gi() {
  int a;
  scanf("%d", &a);
  return a;
}
long long gll() {
  long long a;
  scanf("%lld", &a);
  return a;
}
int main() {
  int n = gi(), k = gi();
  if (k > 3 || k >= n || k == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (k == 2 && n > 4) {
    cout << n - 1 << endl;
    for (int i = 1; i < n; i++) {
      cout << i << " " << i + 1 << endl;
    }
  } else if (k == 3) {
    cout << n - 1 << endl;
    cout << 1 << " " << 2 << endl;
    cout << 2 << " " << 3 << endl;
    cout << 3 << " " << 4 << endl;
    for (int j = 5; j <= n; j++) {
      cout << ((j & 1) ? 2 : 3) << " " << j << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
