#include <bits/stdc++.h>
using namespace std;
const int max_n = 111111, inf = 111111111;
int n, a[max_n], b[max_n];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  int sum = a[0] - b[0], d = sum;
  for (int i = 1; i < n; ++i) {
    sum += a[i] - b[i];
    d = min(d, sum);
  }
  set<int> ans;
  for (int i = 0; i < n; ++i) {
    d = d - (a[i] - b[i]);
    if (d >= 0) {
      if (i + 2 == n + 1) {
        ans.insert(n);
      } else {
        ans.insert(i + 2);
      }
    }
  }
  sum = a[0] - b[n - 1], d = sum;
  for (int i = n - 2; i >= 0; --i) {
    sum += a[i + 1] - b[i];
    d = min(d, sum);
  }
  for (int i = n - 1; i >= 0; --i) {
    d = d - (a[(i + 1) % n] - b[i]);
    if (d >= 0) {
      ans.insert(i + 1);
    }
  }
  cout << ans.size() << endl;
  while (ans.size()) {
    cout << *ans.begin() << ' ';
    ans.erase(ans.begin());
  }
  return 0;
}
