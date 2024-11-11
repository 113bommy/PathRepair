#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1030;
int x[MAXN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> x[i];
  for (int i = 0; i < (n - 1); ++i) {
    for (int j = i + 2; j <= (n - 2); ++j) {
      int a(x[i]), b(x[i + 1]);
      int c(x[j]), d(x[j + 1]);
      if (a > b) swap(a, b);
      if (c > d) swap(c, d);
      if (a < c && c < b && b < d) {
        cout << "yes" << endl;
        return 0;
      }
      if (c < a && a < d && d < b) {
        cout << "yes" << endl;
        return 0;
      }
    }
  }
  cout << "no" << endl;
}
