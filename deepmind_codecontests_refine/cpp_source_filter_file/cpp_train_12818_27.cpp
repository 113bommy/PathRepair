#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, c = 0;
  cin >> n >> x >> y;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if (x > y) {
    cout << n;
    return 0;
  } else {
    for (int i = 0; i < n; i++) {
      if (v[i] < x) c++;
    }
    cout << c - 1;
  }
}
