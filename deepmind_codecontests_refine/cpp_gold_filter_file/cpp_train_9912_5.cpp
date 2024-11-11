#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, s;
    cin >> n >> s;
    long long int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    long long int x = 1;
    int i = 1;
    while (i <= n) {
      if (a[i] > a[x]) x = i;
      s -= a[i];
      if (s < 0) break;
      i++;
    }
    if (s >= 0)
      cout << 0 << endl;
    else
      cout << x << endl;
  }
}
