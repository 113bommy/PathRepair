#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> a(3), b(3);
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;
  int cnt = 0;
  for (int i = 0; i < 3; i++) {
    cnt += (a[i] == b[i]);
  }
  if (cnt < 1)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
