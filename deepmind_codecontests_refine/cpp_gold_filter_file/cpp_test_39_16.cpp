#include <bits/stdc++.h>
using namespace std;
int n;
int ask(int l) {
  cout << "? ";
  for (int i = 0; i < n - 1; i++) cout << 1 << " ";
  cout << l << endl;
  cout.flush();
  int k;
  cin >> k;
  if (k == 0)
    return 1;
  else
    return 0;
}
int ask1(int l, int x) {
  cout << "? ";
  for (int i = 0; i < n - 1; i++) {
    cout << x << " ";
  }
  cout << l << "\n";
  cout.flush();
  int k;
  cin >> k;
  return k;
}
int main() {
  cin >> n;
  int t = 0;
  int k = n;
  for (int i = 0; i < n - 1; ++i) {
    if (ask(i + 2)) {
      break;
    }
    k--;
  }
  int ans[n];
  ans[n - 1] = k;
  for (int i = 1; i <= n; i++) {
    if (i != k) {
      int m = ask1(i, k);
      ans[m - 1] = i;
    }
  }
  cout << "! ";
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  cout << "\n";
  cout.flush();
}
