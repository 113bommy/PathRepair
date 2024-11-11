#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0, max_ = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    max_ = max(max_, a[i]);
  }
  if (sum % 2 == 0 && sum - max_ >= max_) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
