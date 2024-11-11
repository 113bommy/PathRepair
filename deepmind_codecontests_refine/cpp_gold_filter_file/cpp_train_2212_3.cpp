#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, p = 0, sum = 0, c1 = 0, c2 = 0;
    cin >> n;
    int a[n];
    map<int, int> m1;
    map<int, int> m2;
    map<int, int>::iterator it;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m1[a[i] % 2]++;
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++) {
      int x = a[i + 1] - a[i];
      if (x == 1) m2[x]++;
    }
    for (it = m1.begin(); it != m1.end(); it++) {
      c1 = c1 + (it->second) / 2;
    }
    if (c1 * 2 == n) {
      cout << "YES" << endl;
    } else {
      int x = m2[1];
      if ((c1 + x) * 2 >= n)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
  }
}
