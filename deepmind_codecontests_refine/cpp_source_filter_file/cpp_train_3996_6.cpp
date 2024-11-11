#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
class dual {
 public:
  int a, b;
  dual() { b = rand(); }
};
int operator<(const dual& s, const dual& d) { return (s.a < d.a); }
int main() {
  long long n, a[100009], m, w[100009], h[100009], hi = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> w[i] >> h[i];
  }
  for (int i = 0; i < m; i++) {
    long long otv = max(a[w[i] - 1], hi);
    cout << otv;
    hi = otv + h[i];
  }
}
