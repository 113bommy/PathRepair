#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  cout << "1"
       << " " << v[0] << endl;
  int ct = 0;
  while (v[ct] < 0) ct++;
  if (ct >= 2) {
    cout << 2 << " " << v[1] << " " << v[2] << endl;
    cout << n - 3;
    for (int i = 3; i < n; i++) cout << " " << v[i];
  } else {
    cout << 1 << " " << v[n - 1] << endl;
    cout << n - 3;
    for (int i = 1; i < n - 1; i++) cout << " " << v[i];
  }
  return 0;
}
