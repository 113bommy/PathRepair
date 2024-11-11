#include <bits/stdc++.h>
using namespace std;
mt19937::result_type seed =
    chrono::steady_clock::now().time_since_epoch().count();
auto rng =
    std::bind(std::uniform_real_distribution<double>(0, 1), mt19937(seed));
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int array[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> array[i];
  }
  int count = 1;
  int m = 0;
  for (int i = 1; i <= n; i++) {
    count++;
    m = max(array[i], m);
    for (i; i <= m; i++) {
      m = max(array[i], m);
    }
  }
  cout << count;
  return 0;
}
