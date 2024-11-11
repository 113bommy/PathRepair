#include <bits/stdc++.h>
using namespace std;
static long long int r, j, a, b, l, x, y, n, s, q, i, z, p, k, c, d, t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  long long int a[1000001] = {0};
  vector<int> v;
  for (i = 2; i <= 1000000; i++) {
    if (a[i] == 0) {
      for (j = 2 * i; j <= 1000000; j = j + i) a[j] = 1;
    }
  }
  for (int i = 2; i < 1000001; i++) {
    if (a[i] == 0) {
      v.push_back(i);
    }
  }
  for (int j = 0; j < t; j++) {
    cin >> n;
    s = n;
    n = sqrt(n);
    if (n * n == s) {
      if (binary_search(v.begin(), v.end(), n))
        cout << "YES";
      else
        cout << "NO";
    } else
      cout << "NO";
    cout << endl;
  }
}
