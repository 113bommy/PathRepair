#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long i, j, k, l, m, n, a = 1, b = 0;
    cin >> n;
    long long md[n];
    for (i = 0; i < n; i++) cin >> md[i];
    sort(md, md + n);
    for (i = 0; i < n; i++) {
      if (md[i] > a)
        a++;
      else
        a = 1, b++;
    }
    cout << b << endl;
  }
}
