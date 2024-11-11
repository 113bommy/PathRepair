#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int t;
    cin >> t;
    vector<int> v;
    for (int i = 0; i < t; i++) {
      int x;
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    int a = v[v.size() - 1], b = v[v.size() - 2], c = 0;
    for (int i = 0; i < v.size() - 2; i++) {
      c++;
    }
    if (c >= b) {
      c--;
    }
    cout << c << endl;
  }
  return 0;
}
