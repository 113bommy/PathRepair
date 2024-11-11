#include <bits/stdc++.h>
using namespace std;
vector<int> f(int k);
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(f(n)), b(f(m));
  for (int i(0); i < n; i++)
    for (int j(0); j < m; j++) cout << a[i] * b[j] << (j == m - 1 ? '\n' : ' ');
  return 0;
}
vector<int> f(int k) {
  vector<int> ans(k);
  if (k == 1)
    ans[0] = 1;
  else if (k == 2)
    ans[0] = 6, ans[1] = 8;
  else if (k & 1) {
    ans[0] = (k + 1) / 2;
    ans[1] = 2;
    for (int i(2); i < k; i++) ans[i] = 1;
  } else {
    ans[0] = (k + 2) / 2;
    for (int i(1); i < k; i++) ans[i] = 1;
  }
  return ans;
}
