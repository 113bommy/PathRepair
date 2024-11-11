#include <bits/stdc++.h>
using namespace std;
template <typename T>
std::vector<std::vector<std::vector<T>>> make_3d_vector(long long z,
                                                        long long y,
                                                        long long x,
                                                        T value = T{}) {
  return std::vector<std::vector<std::vector<T>>>(
      z, std::vector<std::vector<T>>(y, std::vector<T>(x, value)));
}
template <typename T>
std::vector<std::vector<T>> make_2d_vector(long long z, long long y,
                                           T value = T{}) {
  return std::vector<std::vector<T>>(z, std::vector<T>(y, value));
}
template <typename T>
std::vector<T> make_1d_vector(long long z, T value = T{}) {
  return std::vector<T>(z, value);
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 1; i < n; i++) {
    if (i % 2)
      cout << "I hate that ";
    else
      cout << "I love that";
  }
  if (n % 2)
    cout << "I hate it";
  else
    cout << "I love it";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test = 1;
  while (test--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}
