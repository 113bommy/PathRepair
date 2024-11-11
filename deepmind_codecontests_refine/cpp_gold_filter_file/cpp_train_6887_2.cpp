#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long k, l;
  cin >> k >> l;
  long long cnt = 0;
  while (l % k == 0) {
    l = l / k;
    cnt++;
  }
  if (l == 1 && cnt > 0) {
    cout << "YES\n" << cnt - 1;
  } else {
    cout << "NO";
  }
  return 0;
}
