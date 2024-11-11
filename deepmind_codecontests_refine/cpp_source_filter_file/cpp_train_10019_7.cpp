#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void solve() {
  long long int n;
  cin >> n;
  long long int arr[n];
  for (int i = 0; i < (n); ++i) cin >> arr[i];
  for (int i = 1; i <= (n); ++i) {
    if (arr[i] > arr[i - 1]) {
      if (arr[i] != arr[i - 1] + 1) {
        cout << "No" << '\n';
        return;
      }
    }
  }
  cout << "Yes" << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
