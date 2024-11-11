#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> v;
  for (int i = 1; i < 2000; ++i) {
    if (i % 3 == 0 or i % 10 == 3) {
      continue;
    } else
      v.push_back(i);
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << v[n - 1] << endl;
  }
}
