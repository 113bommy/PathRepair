#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 100;
long long int n, m, mx, in, x;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  long long int a[n];
  fill(a, a + n, 0);
  for (long long int i = 0; i < m; i++) {
    mx = 0;
    for (long long int j = 0; j < n; j++) {
      cin >> x;
      if (x > mx) {
        in = j;
        mx = x;
      }
    }
    a[in]++;
  }
  mx = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] > mx) {
      mx = a[i];
      in = i + 1;
    }
  }
  cout << in << endl;
}
