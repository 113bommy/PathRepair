#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], s = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  int c = 0, cur = a[0];
  vector<int> v;
  v.push_back(1);
  for (int i = 1; i < n; i++) {
    if (a[0] >= a[i] * 2) {
      cur += a[i];
      v.push_back(i + 1);
      c++;
    }
  }
  if (cur >= s / 2) {
    cout << v.size() << endl;
    for (auto i = v.begin(); i != v.end(); i++) {
      cout << *i << " ";
    }
    cout << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
