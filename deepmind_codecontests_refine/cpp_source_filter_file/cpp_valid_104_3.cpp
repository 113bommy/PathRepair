#include <bits/stdc++.h>
using namespace std;
void calc(vector<int> &arr, vector<int> &ids, int l, int r) {
  for (int i = r - 2; i >= l; i -= 2) {
    ids.push_back(i);
    int v = arr[i] ^ arr[i + 1] ^ arr[i + 2];
    arr[i] = arr[i + 1] = arr[i + 2] = v;
  }
  for (int i = l; i <= r - 2; i++) {
    ids.push_back(i);
    int v = arr[i] ^ arr[i + 1] ^ arr[i + 2];
    arr[i] = arr[i + 1] = arr[i + 2] = v;
  }
}
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n + 1), pre(n + 1), ids;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    pre[i] = pre[i - 1] ^ arr[i];
  }
  if (pre[n] != 0) {
    cout << "NO\n";
    return;
  }
  if (n & 1)
    calc(arr, ids, 1, n);
  else {
    bool f = false;
    for (int i = 1; !f && i <= n; i += 2) {
      if (pre[i] == 0) {
        f = true;
        calc(arr, ids, 1, i);
        calc(arr, ids, i + 1, n);
      }
    }
    if (!f) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  if (ids.empty()) {
    cout << "0\n";
    return;
  }
  cout << (int)ids.size() << "\n";
  for (int id : ids) cout << id << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) solve();
  return 0;
}
