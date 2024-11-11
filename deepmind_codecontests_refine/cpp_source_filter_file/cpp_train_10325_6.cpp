#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
    sum += x;
  }
  sort(v.begin(), v.end());
  if (sum % 2 == 0 && v[n - 1] <= sum - v[n - 1]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
