#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    a.push_back(b);
  }
  for (int i = 0; i < n; i++) {
    int qq = 0;
    for (int j = 1; j < n; j++) {
      if (abs(a[j] - a[j - 1]) > 1) {
        cout << "NO" << endl;
        return 0;
      }
      if (a[j] > a[qq]) {
        qq = j;
      }
    }
    int o = a[qq];
    a.erase(a.begin() + qq);
    a.push_back(o);
  }
  for (int j = 1; j < n; j++) {
    if (abs(a[j] - a[j - 1]) > 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
