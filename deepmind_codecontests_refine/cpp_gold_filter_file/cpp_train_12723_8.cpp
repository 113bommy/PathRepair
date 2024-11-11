#include <bits/stdc++.h>
using namespace std;
int a[100001], n, s;
vector<int> v;
int main() {
  cin >> n;
  s = n;
  if (n % 2 == 1) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[0] == a[n - 1] && n > 1) {
    cout << "NO";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] - a[i - 1] > 1) {
      cout << "NO";
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int e = 1;
    while (i + 1 < n && a[i] == a[i + 1]) {
      e++;
      i++;
    }
    v.push_back(e);
  }
  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i] > v[i + 1] || (v[i] == v[i + 1] && i + 1 != v.size() - 1)) {
      cout << "NO";
      return 0;
    } else {
      v[i + 1] -= v[i];
      s -= 2 * v[i];
    }
  }
  if (s != 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
}
