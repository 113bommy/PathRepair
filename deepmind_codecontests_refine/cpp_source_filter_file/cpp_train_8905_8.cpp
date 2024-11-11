#include <bits/stdc++.h>
using namespace std;
template <typename T>
void sci(T& t) {
  cin >> t;
}
template <typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
  sci(t);
  sci(ts...);
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  sci(n);
  long long r = 2;
  for (int i = 1; i <= n; i++) {
    long long x = 1LL * i * (i + 1) * (i + 1) - r / i;
    cout << x << "\n";
    r = i * (i + 1);
  }
  return 0;
}
