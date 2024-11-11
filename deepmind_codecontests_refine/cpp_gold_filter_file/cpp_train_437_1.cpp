#include <bits/stdc++.h>
using namespace std;
int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    vector<int> v;
    v.push_back(a[0]);
    for (int i = 1; i < n; i++) {
      if (a[i] != v.back())
        v.push_back(a[i]);
      else
        continue;
    }
    cout << v.size() << endl;
  }
  return 0;
}
