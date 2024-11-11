#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> b[100005];
  for (int i = 0; i < n; ++i) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(b, b + n);
  b[n].first = -1;
  int st = 0, en = 0, mx = 1, mxst = 0, mxen = 0;
  for (int i = 1; i <= n; ++i) {
    if (b[i].first != b[i - 1].first) {
      if (mx < i - st ||
          (mx == i - st && mxen - mxst < b[i - 1].second - b[st].second)) {
        mx = i - st;
        mxst = b[st].second;
        mxen = b[i - 1].second;
      }
      st = i;
    }
  }
  cout << mxst + 1 << " " << mxen + 1;
}
