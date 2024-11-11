#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> b;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int j = n / i;
      if (j != 2) b.push_back(i);
      if (i != 2) b.push_back(j);
    }
  }
  int res = 0;
  for (auto &elem : a) res += elem;
  for (int i = 0; i < b.size(); i++) {
    for (int j = 0; j < b[i]; j++) {
      int sum = 0;
      for (int k = i + j; k < n; k += b[i]) sum += a[k];
      if (sum > res) res = sum;
    }
  }
  cout << res << endl;
  return 0;
}
