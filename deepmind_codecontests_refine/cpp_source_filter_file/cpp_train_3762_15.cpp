#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long m = 0;
  vector<int> a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    a.push_back(val);
  }
  sort(a.begin(), a.end());
  for (int i = 1; i < n / 2; i++) {
    m += (a[i - 1] + a[n - i]) * (a[i - 1] + a[n - i]);
  }
  cout << m;
  return 0;
}
