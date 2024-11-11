#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
bool Check(int n) {
  if (n == 1) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
void TestCase() {
  int n;
  cin >> n;
  if (Check(n))
    cout << 1 << "\n" << n;
  else {
    if (Check(n - 2))
      cout << 2 << "\n" << n - 2 << " " << 2;
    else {
      if (Check(n - 4))
        cout << 3 << "\n" << 2 << " " << 2 << " " << n - 4 << "\n";
      else {
        int a, b, c;
        for (int i = n - 1; i >= max(0, n - 300); i--) {
          if (Check(i)) {
            a = i;
            break;
          }
        }
        n = n - a;
        for (int i = 1; i < n; i++) {
          if (Check(i) && Check(n - i)) {
            b = i;
            c = n - i;
            break;
          }
        }
        cout << 3 << "\n" << a << " " << b << " " << c << "\n";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T = 1;
  while (T--) {
    TestCase();
  }
  return 0;
}
