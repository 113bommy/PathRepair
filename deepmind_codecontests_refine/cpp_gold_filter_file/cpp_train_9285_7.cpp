#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto& it : a) cin >> it;
  if (n == 1) {
    cout << a[0] * a[0];
    return 0;
  }
  int k = (n + 1) / 2;
  long long s1 = 0, s2 = 0;
  int count = 0;
  sort(a.begin(), a.end());
  for (int i = n - 1; i >= 0; i--) {
    if (k > count) {
      s1 += a[i];
      count++;
    } else {
      s2 += a[i];
    }
  }
  cout << s1 * s1 + s2 * s2;
  return 0;
}
