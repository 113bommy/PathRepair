#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int sum = 0;
  for (int i = 0; i < n / 2; i++) {
    sum = sum + (v[i] + v[n - i - 1]) * (v[i] + v[n - i - 1]);
  }
  cout << sum;
  return 0;
}
