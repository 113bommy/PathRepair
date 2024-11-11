#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a, b;
vector<int> build(int x) {
  vector<int> ans;
  if (x < 3) {
    if (x == 1)
      ans.push_back(1);
    else
      ans.push_back(3), ans.push_back(4);
    return ans;
  }
  for (int i = 0; i < x - 2; i++) ans.push_back(1);
  if (x % 2)
    ans.push_back(2), ans.push_back((x / 2) + 1);
  else
    ans.push_back(1), ans.push_back((x / 2) - 1);
  return ans;
}
int main() {
  cin >> n >> m;
  a = build(n);
  b = build(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << a[i] * b[i] << ' ';
    cout << endl;
  }
  return 0;
}
