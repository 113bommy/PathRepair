#include <bits/stdc++.h>
using namespace std;
const int N = 200007, M = 200001, mod = 1000000007, inf = 1000000007;
const long long lmod = 1000000007, linf = 1e18 + 77;
const long double eps = 1e-9;
int a[N];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  scanf("%d", &n);
  ;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        cout << j << " " << j + 1 << endl;
      }
    }
  }
}
