#include <bits/stdc++.h>
using namespace std;
long long v[100001];
int main() {
  long long n, b[100001];
  cin >> n;
  string a;
  cin >> a;
  for (int k = 0; k < n; k++) cin >> b[k];
  int t = 0;
  if (a[0] == '<') {
    cout << "FINITE";
    return 0;
  }
  for (int k = 0; k < 2 * n; k++) {
    if (a[t] == '>') {
      if (v[t] == 1) {
        cout << "INFINITE";
        return 0;
      } else
        v[t] = 1;
      t = t + b[t];
    } else {
      if (v[t] == 1) {
        cout << "INFINITE";
        return 0;
      } else
        v[t] = 1;
      t = t - b[t];
    }
    if (t < 0 || t >= n) {
      cout << "FINITE";
      return 0;
    }
  }
  return 0;
}
