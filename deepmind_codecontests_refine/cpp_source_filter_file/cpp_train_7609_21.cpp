#include <bits/stdc++.h>
using namespace std;
long long n, i, mx, j, a, c = 0, mn;
int main() {
  cin >> n;
  vector<int> v(n);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  for (i = 1; i < n; i++) {
    c = c + (v[i] - v[i - 1]);
  }
  cout << c;
}
