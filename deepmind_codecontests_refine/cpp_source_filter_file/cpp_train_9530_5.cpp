#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int a, b, c, d, i;
int f(long long k) {
  int i;
  for (i = 2; i <= sqrt(k); i++)
    if (k % i == 0) return 0;
  return 1;
}
void f1() {
  for (i = 2; i <= sqrt(a); i++) {
    if (a % i == 0) cout << 0 << endl;
  }
  cout << 1 << endl;
}
int main() {
  cin >> a;
  while (a--) {
    string s;
    cin >> s >> b >> c;
    if (b >= 2400 && c > 2400) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
