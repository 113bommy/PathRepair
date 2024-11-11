#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, l = 0, s = 101, t = 1, i, j;
  cin >> n >> k;
  long long a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    l = max(l, a[i]);
    s = min(s, a[i]);
  }
  if (l > (k + s))
    cout << "NO";
  else {
    cout << "YES" << endl;
    for (i = 0; i < n; i++) {
      t = 1;
      for (j = 0; j < a[i]; j++) {
        if (t <= k) {
          cout << t << " ";
        } else {
          t = 1;
          cout << t << " ";
        }
        t++;
      }
      cout << endl;
    }
  }
}
