#include <bits/stdc++.h>
using namespace std;
template <typename T>
void showv(vector<T> &v) {
  int size = v.size();
  for (int i = 0; i < size; i++) cout << v[i] << " ";
  cout << endl;
}
template <typename T>
vector<T> inputv(int n) {
  vector<T> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cout << i << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
