#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l;
  cin >> n >> l;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long max_l = *max_element(a.begin(), a.end());
  long long max_area = 0;
  for (int i = l; i <= max_l; i++) {
    long long area = 0;
    for (auto e : a) {
      area += e / i * i;
    }
    max_area = max(max_area, area);
  }
  cout << max_area;
  return 0;
}
