#include <bits/stdc++.h>
using namespace std;
int ask(int a, int b) {
  cout << '?' << a + 1 << ' ' << b + 1 << '\n';
  int z;
  cin >> z;
  cout.flush();
  return z;
}
int main() {
  int n;
  cin >> n;
  vector<int> ans(n, -1);
  int mx = 0;
  for (int i = 1; i < n; i++) {
    int a = ask(mx, i);
    int b = ask(i, mx);
    if (a > b) {
      ans[mx] = a;
      mx = i;
    } else {
      ans[i] = b;
    }
  }
  ans[mx] = n;
  cout << "! ";
  for (int i = (0); (1) > 0 ? i < (n) : i > (n); i += (1))
    cout << ans[i] << ' ';
  cout << '\n';
  return 0;
}
