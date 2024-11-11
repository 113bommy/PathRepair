#include <bits/stdc++.h>
using namespace std;
const int mxN = 2e5;
const int MOD = 1e9 + 7;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, r;
    long long ans;
    cin >> n >> r;
    if (n >= r) {
      ans = r * (r + 1) / 2;
    } else {
      ans = n * (n - 1) / 2 + 1;
    }
    cout << ans << "\n";
  }
}
