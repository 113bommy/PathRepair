#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
std::pair<T, U> operator+(const std::pair<T, U>& l, const std::pair<T, U>& r) {
  return {l.first + r.first, l.second + r.second};
}
typedef void (*callback_function)(void);
const long long INF64 = 1e18;
const long long INF32 = 1e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  {
    long long n;
    cin >> n;
    long long res = n, prev, cur;
    cin >> prev;
    res += prev;
    for (long long i = (1); i < (n); i++) {
      cin >> cur;
      res += abs(cur - prev);
      prev = cur;
    }
    cout << res << endl;
  }
  return 0;
}
