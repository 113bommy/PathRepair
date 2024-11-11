#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  int result = 0;
  for (int i = 0; i < n; ++i) {
    int a_value = 0, b_value = 0;
    for (int j = i; j < n; ++j) {
      a_value |= a[j];
      b_value |= b[j];
      result = max(result, a_value + b_value);
    }
  }
  cout << result << endl;
  return 0;
}
