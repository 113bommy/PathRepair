#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int N = 2e6 + 13, M = N;
vector<int> g[N];
int arr[N];
vector<int> a;
int n, m, k;
void solve() {
  int i, j;
  cin >> n >> k;
  int h[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  int sum = 0, mn = INT_MAX;
  for (int i = 0; i < k; i++) {
    sum += h[i];
  }
  mn = min(mn, sum);
  int l = 0, r = k, idx = 0;
  while (r < n) {
    sum -= h[l];
    sum += h[r];
    if (sum < mn) {
      idx = l + 1;
      mn = sum;
    }
    l++;
    r++;
  }
  cout << idx + 1;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  srand(chrono::high_resolution_clock::now().time_since_epoch().count());
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
