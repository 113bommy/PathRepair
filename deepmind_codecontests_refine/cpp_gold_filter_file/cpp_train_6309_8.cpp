#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9) + 123;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
int main() {
  boost();
  long long n, m;
  cin >> n >> m;
  if (n % m == 0 && n / m % 2 != 0) {
    cout << "YES";
    return 0;
  } else {
    if (n / m % 2 == 0) {
      cout << "NO";
      return 0;
    } else {
      cout << "YES";
      return 0;
    }
  }
  exit(0);
}
