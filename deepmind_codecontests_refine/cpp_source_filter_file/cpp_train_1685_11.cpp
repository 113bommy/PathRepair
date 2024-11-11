#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, r = 0, m = 0, t;
  vector<int> v;
  cin >> t;
  while (t--) {
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
    }
    int lo = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      if (v[i] < lo)
        lo = v[i];
      else
        s++;
    }
    cout << s << endl;
    v.clear();
  }
}
