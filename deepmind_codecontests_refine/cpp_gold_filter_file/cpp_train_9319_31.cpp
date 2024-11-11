#include <bits/stdc++.h>
using namespace std;
int ors(int l, int r, vector<int> vec) {
  int ret = vec[l];
  for (int i = l + 1; i <= r; i++) ret |= vec[i];
  return ret;
}
int main() {
  int n, ret = 0;
  cin >> n;
  vector<int> foo(n), bar(n);
  for (int i = 0; i < n; i++) cin >> foo[i];
  for (int i = 0; i < n; i++) cin >> bar[i];
  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= i; j--)
      ret = max(ret, ors(i, j, foo) + ors(i, j, bar));
  }
  cout << ret << endl;
}
