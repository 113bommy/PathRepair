#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200010;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 0) {
    for (int i = 1; i <= n; i++) {
      if (i > 1) cout << " ";
      cout << i;
    }
    cout << endl;
  } else {
    vector<int> v;
    for (int i = 1; i < n - k; i++) {
      v.push_back(i);
    }
    for (int i = n; i >= n - k; i--) {
      v.push_back(i);
    }
    for (int i = 0; i < v.size(); i++) {
      if (i) cout << " ";
      cout << v[i];
    }
    cout << endl;
  }
  return 0;
}
