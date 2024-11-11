#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (size_t i = 1; i <= 200; i++) {
    if (a <= i && 2 * a >= i)
      for (size_t j = 1; j < i; j++) {
        if (b <= j && 2 * b >= j)
          for (size_t l = 1; l < j; l++) {
            if (c <= l && 2 * c >= l)
              if (2 * d < i && 2 * d < j && 2 * d >= l && d <= l) {
                cout << i << endl << j << endl << l << endl;
                return 0;
              }
          }
      }
  }
  cout << -1;
}
