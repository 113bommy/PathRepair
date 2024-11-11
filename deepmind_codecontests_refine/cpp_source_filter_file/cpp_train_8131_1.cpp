#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k, temp;
  cin >> n >> k;
  set<long long int> s;
  for (long long int i = 0; i < n; i++) {
    cin >> temp;
    s.insert(temp);
  }
  long long int val = 0, i = 0;
  auto it = s.begin();
  while (i < k) {
    if (it != s.end()) {
      cout << *it - val << endl;
      val += *it;
      it++;
    } else {
      cout << 0 << endl;
    }
    i++;
  }
  return 0;
}
