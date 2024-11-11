#include <bits/stdc++.h>
int arr[5];
using namespace std;
int main() {
  int n;
  int cnt = 1;
  cin >> n;
  int t1, t2;
  int cr1 = 0, cr2 = 0;
  int mx = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> t1 >> t2;
    if (t1 == cr1 && t2 == cr2)
      ++cnt;
    else {
      cnt = 1;
    }
    res = max(res, cnt);
    cr1 = t1;
    cr2 = t2;
  }
  cout << res << endl;
  return 0;
}
