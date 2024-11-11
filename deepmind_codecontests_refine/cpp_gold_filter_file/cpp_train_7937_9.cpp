#include <bits/stdc++.h>
using namespace std;
const long long MAX = 3e5 + 5;
const long long INF = 2e18;
const long long MOD = 1e9 + 7;
int main() {
  int i, j, k, l, p, q, n;
  vector<int> vec;
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n + 1];
    for (i = 1; i <= n; i++) cin >> a[i];
    vec.clear();
    for (i = 1; i <= n; i++) {
      if (a[i] != i) vec.push_back(i);
    }
    l = vec.size();
    if (l == 0)
      cout << "0\n";
    else {
      p = 0;
      for (i = 0; i < l - 1; i++) {
        if (vec[i + 1] - vec[i] > 1) p++;
      }
      if (p == 0)
        cout << "1\n";
      else
        cout << "2\n";
    }
  }
}
