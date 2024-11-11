#include <bits/stdc++.h>
using namespace std;
int query(vector<int>& v) {
  cout << "? ";
  for (auto& x : v) {
    cout << x << " ";
  }
  cout << endl;
  int a;
  cin >> a;
  return a;
}
void solve(int n) {
  int x = 1;
  vector<int> v(n, 1);
  for (int i = n; i >= 2; i--) {
    for (int j = 0; j < n - 1; j++) {
      v[j] = i;
    }
    int a = query(v);
    if (a == 0) continue;
    x = a;
    break;
  }
  vector<int> ans(n, -1);
  ans[n - 1] = x;
  for (int i = 0; i < n; i++) {
    v[i] = x;
  }
  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    v[n - 1] = i;
    int index = query(v);
    ans[index - 1] = i;
  }
  cout << "! ";
  for (auto& y : ans) {
    cout << y << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  while (t--) {
    int n;
    cin >> n;
    solve(n);
  }
}
