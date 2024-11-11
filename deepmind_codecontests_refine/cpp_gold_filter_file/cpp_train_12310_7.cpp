#include <bits/stdc++.h>
const int N = 1e3 + 10;
using namespace std;
int a[N], b[N], c[N];
char str1[N], str2[N], str3[N];
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long n, k, sum{0}, suma{0}, sumb{0};
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      suma += a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
      sumb += b[i];
    }
    if (k > 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n - 1; ++j) {
          if (a[i] >= a[j + 1]) swap(a[i], a[j + 1]);
          if (b[i] <= b[j + 1]) swap(b[i], b[j + 1]);
        }
      }
      for (int i = 0; i < k; ++i) {
        if (a[i] < b[i]) swap(a[i], b[i]);
      }
      for (int i = 0; i < n; ++i) {
        sum += a[i];
      }
      cout << sum << "\n";
    } else
      cout << suma << "\n";
  }
}
