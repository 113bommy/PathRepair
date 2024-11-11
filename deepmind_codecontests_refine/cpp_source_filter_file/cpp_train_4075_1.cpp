#include <bits/stdc++.h>
using namespace std;
int n;
bool t;
int main() {
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  cout << v[n - 1] << " ";
  int x = v[n - 1];
  for (int i = n - 1; i > 0; i--) {
    if (x % v[i] != 0) {
      cout << v[i] << endl;
      t = false;
      return 0;
    }
  }
  if (t == false) {
    for (int i = n - 1; i > 0; i++) {
      if (i - 1 >= 0 && v[i] == v[i - 1]) {
        cout << v[i] << endl;
        return 0;
      }
    }
  }
  return 0;
}
