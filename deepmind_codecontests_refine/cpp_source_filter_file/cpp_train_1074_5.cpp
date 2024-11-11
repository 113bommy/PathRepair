#include <bits/stdc++.h>
using namespace std;
int main() {
  cout.precision(5);
  int n;
  int a, b;
  double total = 0;
  int tmp = 0;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());
  int i = n % 2;
  if (n % 2) tmp += v[0];
  while (i < n - 1) {
    tmp += v[i + 1] * v[i + 1] - v[i] * v[i];
    i += 2;
  }
  cout << fixed << tmp * M_PI << endl;
  ;
}
