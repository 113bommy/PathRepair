#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename T>
void DEBUG(string label, T value) {
  cerr << "[" << label << " = " << value << "]\n";
}
void solve() {
  int n, k;
  cin >> n >> k;
  int arr[n];
  bool found = false;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] == k) {
      found = true;
    }
  }
  if (!found) {
    cout << "no\n";
    return;
  }
  if (n == 1) {
    cout << "yes\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = i; j < n && j < i + 3; j++) {
      cnt += (arr[j] >= k);
    }
    if (cnt >= 2) {
      cout << "yes\n";
      return;
    }
  }
  cout << "no\n";
}
int main(int argv, char **argc) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
