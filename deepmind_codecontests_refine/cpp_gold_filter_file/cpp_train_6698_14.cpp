#include <bits/stdc++.h>
using namespace std;
vector<int> rev(vector<int> a) {
  vector<int> ans(a.size());
  for (int i = 0; i < a.size(); i++) {
    ans[a[i]] = i;
  }
  return ans;
}
vector<int> mult(vector<int> a, vector<int> b) {
  vector<int> ans(a.size());
  for (int i = 0; i < a.size(); i++) {
    ans[i] = a[b[i]];
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  vector<int> d = mult(rev(a), b);
  for (int i = 1; i <= n; i++) {
    cout << d[i] << " ";
  }
  cout << endl;
  return 0;
}
