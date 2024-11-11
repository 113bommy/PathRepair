#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  v.push_back(-1);
  int first = 0, res = 0;
  int i = 1;
  for (; i < n; ++i) {
    if (v[i] != v[i - 1] + 1) {
      if (v[first] == 1 || v[i - 1] == 1000) {
        res = max(res, i - first - 1);
      } else {
        res = max(res, i - first - 2);
      }
      first = i;
    }
  }
  cout << res << endl;
  return 0;
}
