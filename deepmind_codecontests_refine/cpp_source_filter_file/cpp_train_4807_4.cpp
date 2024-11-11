#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  bool flag = 0;
  cin >> n;
  vector<unsigned long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  if (v[n - 1] >= (v[n - 2] + v[n - 3])) {
    cout << "No" << endl;
    return 0;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n - 2; ++i) {
    cout << v[i] << " ";
  }
  cout << v[n - 1] << " " << v[n - 2] << endl;
  return 0;
}
