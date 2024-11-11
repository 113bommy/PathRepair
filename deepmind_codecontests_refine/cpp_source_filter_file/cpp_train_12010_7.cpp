#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(0);
  cout << fixed;
  int n, input;
  bool flag = false;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  if (v.size() > 1) {
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++) {
      if (v[i] != v[0]) {
        cout << v[i] << endl;
        flag = true;
        break;
      }
    }
    if (!flag) cout << "NO";
  } else {
    cout << "NO";
  }
  return 0;
}
