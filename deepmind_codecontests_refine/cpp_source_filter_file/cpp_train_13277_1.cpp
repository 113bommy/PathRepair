#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, m = 0;
  cin >> n;
  vector<long long> v;
  int a[100001];
  fill(a, a + 100001, 0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > 100000) x = 100000;
    a[x]++;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      a[i]++;
      m++;
    } else if (a[i] > 1) {
      while (m > 0 && a[i] > 0) {
        m--;
        a[i]--;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x < a[i]; x++) {
      v.push_back(i);
      if (v.size() == n) break;
    }
    if (v.size() == n) break;
  }
  cout << *max_element(v.begin(), v.end()) + 1 << endl;
}
