#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int arr[n - 1];
  vector<pair<int, int>> primes;
  int next_num = 1;
  for (int i = 2; i <= n; ++i) {
    bool done = false;
    for (auto x : primes) {
      if (i % x.first == 0) {
        arr[i - 2] = x.second;
        done = true;
        break;
      }
    }
    if (!done) {
      arr[i - 2] = next_num;
      primes.push_back({i, next_num});
      next_num++;
    }
  }
  if (n > 0) {
    for (int i = 0; i < n - 2; ++i) {
      cout << arr[i] << " ";
    }
    cout << arr[n - 2] << "\n";
  }
}
