#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#pragma GCC optimize("trapv")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " : " << a << endl;
  err(++it, args...);
}
int main() {
  long long int m, n;
  cin >> n >> m;
  if (m == 3) {
    if (n == 3) {
      cout << "0 0" << endl << "0 1" << endl << "1 0";
      return 0;
    } else if (n == 4) {
      cout << "0 0" << endl << "3 0" << endl << "0 3" << endl << "1 1";
      return 0;
    } else if (n >= 5) {
      cout << -1 << endl;
      return 0;
    }
  }
  long long int inf = 10000;
  for (long long int i = 0; i < (m); ++i)
    cout << i << " " << inf + i * i << endl;
  for (long long int i = 0; i < (n - m); ++i)
    cout << i << " " << -inf - i * i << endl;
  return 0;
}
