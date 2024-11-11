#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string arr;
  cin >> arr;
  vector<int> l(n), r(n);
  int g = 0;
  if (arr[0] == 'G') {
    l[0] = 1;
    g++;
  }
  if (arr.back() == 'G') {
    r.back() = 1;
  }
  for (int i = 1; i < n; i++) {
    if (arr[i] == 'G') {
      l[i] = l[i - 1] + 1;
      g++;
    } else
      l[i] = 0;
  }
  for (int i = arr.size() - 2; i >= 0; i--) {
    if (arr[i] == 'G')
      r[i] = r[i + 1] + 1;
    else
      r[i] = 0;
  }
  int res = 0, without = l[0];
  for (int i = 1; i < n - 1; i++) {
    if (arr[i] == 'S') {
      int tmp = l[i - 1] + r[i + 1];
      if (tmp < g) {
        tmp++;
      }
      res = max(res, tmp);
    } else {
      without = max(without, l[i]);
    }
  }
  without = max(without, l.back());
  if (res == without)
    cout << res;
  else
    cout << max(res, without);
}
