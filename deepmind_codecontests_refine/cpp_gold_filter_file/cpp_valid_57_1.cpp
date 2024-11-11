#include <bits/stdc++.h>
using namespace std;
void rev(vector<int> &a, int l) { reverse(a.begin(), a.begin() + l); }
void swap_h(vector<int> &a, int n, vector<int> &v) {
  int i = (find(a.begin(), a.end(), n) - a.begin());
  rev(a, i + 1);
  v.push_back(i + 1);
  int j = (find(a.begin(), a.end(), n - 1) - a.begin());
  rev(a, j);
  v.push_back(j);
  rev(a, j + 2);
  v.push_back(j + 2);
  rev(a, 3);
  v.push_back(3);
  rev(a, n);
  v.push_back(n);
}
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    bool pos = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == i % 2) pos = false;
    }
    if (!pos) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> v;
    for (int i = n; i >= 3; i -= 2) {
      swap_h(a, i, v);
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << ' ';
    }
    cout << '\n';
  }
}
