#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 23;
const int MOD = 1e9 + 9;
const int ARRS = 1e3 + 100;
int arr[ARRS];
bool inside(int x, int a, int b) { return min(a, b) < x && x < max(a, b); }
bool outside(int x, int a, int b) { return x < min(a, b) || max(a, b) < x; }
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  bool cut = false;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    for (int j = 1; j <= i - 1; ++j) {
      cut |= inside(arr[j - 1], arr[i - 1], arr[i]) &&
             outside(arr[j], arr[i - 1], arr[i]);
      cut |= outside(arr[j - 1], arr[i - 1], arr[i]) &&
             inside(arr[j], arr[i - 1], arr[i]);
    }
  }
  cout << (cut ? "yes" : "no") << "\n";
  return 0;
}
