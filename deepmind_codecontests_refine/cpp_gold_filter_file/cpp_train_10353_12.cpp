#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, val, vm;
  set<int> s;
  cin >> n;
  cin >> vm;
  int a[n][n];
  for (int i = 0; i < n; i++) {
    cin >> k;
    for (int j = 0; j < k; j++) {
      cin >> val;
      if (vm > val) s.insert(i);
    }
  }
  cout << s.size() << endl;
  for (auto it = s.begin(); it != s.end(); it++) cout << *it + 1 << " ";
}
