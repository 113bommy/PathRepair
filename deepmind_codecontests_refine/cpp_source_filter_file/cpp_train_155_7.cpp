#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n, k;
  cin >> n >> k;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  v.push_back(a);
  v.push_back(c);
  for (int i = 1; i <= n; i++) {
    if (i != a && i != b && i != c && i != d) v.push_back(i);
  }
  v.push_back(d);
  v.push_back(b);
  if (k >= n + 1) {
    for (int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
    swap(v[0], v[1]);
    swap(v[n - 1], v[n - 2]);
    for (int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
  } else {
    cout << -1 << "\n";
  }
}
