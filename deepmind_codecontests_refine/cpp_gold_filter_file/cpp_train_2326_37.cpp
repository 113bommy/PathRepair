#include <bits/stdc++.h>
using namespace std;
void run() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
}
void solve() {
  long d;
  cin >> d;
  int n;
  cin >> n;
  long long res = 0;
  vector<long long> arr(n);
  for (int i = 0; i < (int)(n); i++) cin >> arr[i];
  for (int i = 0; i < (int)n - 1; i++) res += d - arr[i];
  cout << res << endl;
}
int main() {
  run();
  solve();
  return 0;
}
