#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, m = 0;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      m = max(m, a[i]);
    }
    set<int> s(a, a + n);
    int sum1 = 0, temp = 0;
    for (int i = 0; i < k; i++) {
      sum1 += a[i];
    }
    for (int j = 0; j <= n - k; j++) {
      int sum = 0;
      for (int i = j; i < j + k; i++) {
        sum += a[i];
      }
      if (sum != sum1) {
        temp = 1;
        break;
      }
    }
    if (temp == 0) {
      cout << n << endl;
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
      cout << endl;
      continue;
    }
    if (s.size() > k) {
      cout << "-1" << endl;
      continue;
    }
    vector<int> v;
    int u = k, v1 = k;
    while (n--) {
      u = v1;
      for (auto i = s.begin(); i != s.end(); i++) {
        v.push_back(*i);
      }
      while (s.size() < u) {
        v.push_back(1);
        u--;
      }
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
}
