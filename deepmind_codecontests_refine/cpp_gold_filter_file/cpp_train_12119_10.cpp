#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  int ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    if (v[i] == i)
      ans++;
    else if (v[v[i]] == i) {
      cnt = 1;
    }
  }
  cout << min(ans + cnt + 1, n);
  return 0;
}
