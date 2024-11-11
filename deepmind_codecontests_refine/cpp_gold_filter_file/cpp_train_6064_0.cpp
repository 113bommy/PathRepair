#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    int x;
    cin >> x;
    if (x == 1) {
      cout << 2 << endl;
      return 0;
    } else {
      cout << 1 << endl;
      return 0;
    }
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  bool ase = 1;
  int get = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] > 1) {
      get = v[i];
      break;
    }
  }
  if (get != -1) {
    v.push_back(1);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    return 0;
  } else {
    v.push_back(2);
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
      cout << v[i] << " ";
    }
    return 0;
  }
}
