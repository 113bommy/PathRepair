#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> a(n);
  int less = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < x) {
      less++;
    }
  }
  int res = 0;
  if (x <= y) {
    res = less % 2 == 0 ? less / 2 : less / 2 + 1;
  } else {
    res = n;
  }
  cout << res << endl;
}
