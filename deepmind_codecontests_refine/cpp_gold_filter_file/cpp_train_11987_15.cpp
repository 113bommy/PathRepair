#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
int main(int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  long long n, k;
  cin >> n >> k;
  if (n > k * k - k) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  int i = 0;
  for (int s = 1; s <= k; ++s) {
    for (int p = s + 1; p <= k; ++p) {
      cout << s << ' ' << p << '\n';
      if (++i == n) return 0;
      cout << p << ' ' << s << '\n';
      if (++i == n) return 0;
    }
  }
  return 0;
}
