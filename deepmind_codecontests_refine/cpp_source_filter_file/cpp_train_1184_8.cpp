#include <bits/stdc++.h>
const double PI =
    3.141592653589793238462643383279502884197169399375105820974944;
using namespace std;
void solve() {
  long long n, k;
  cin >> n >> k;
  if (n == 1) {
    cout << "-1"
         << "\n";
    return;
  }
  if ((k * (k - 1)) / 2 < n - 1) {
    cout << "-1"
         << "\n";
  } else {
    long long start = 1, end = k - 1;
    while (start < end) {
      long long mid = (start + end) / 2;
      long long suff = (k * (k - 1)) / 2 - (mid * (mid - 1)) / 2;
      if (suff == n - 1) {
        cout << k - start << "\n";
        return;
      } else if (suff > n - 1) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    long long suff = (k * (k - 1)) / 2 - (start * (start - 1)) / 2;
    if (suff >= n - 1) {
      cout << k - start << "\n";
    } else {
      cout << k - start + 1 << "\n";
    }
  }
}
int main() {
  bool testing = false;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (testing) {
    freopen("test1.txt", "rt", stdin);
    int start = clock();
    solve();
    int end = clock();
    cout << "time: " << (end - start) / (double)(CLOCKS_PER_SEC)*1000
         << " milliseconds\n";
  } else {
    solve();
  }
}
