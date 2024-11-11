#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 123;
const long long INF = (long long)1e18 + 123;
const int inf = (int)1e9 + 123;
int n;
int main() {
  cin >> n;
  if (n <= 3) {
    puts("NO");
    return 0;
  }
  puts("YES");
  if (n % 2 == 0) {
    cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n";
    for (int i = 5; i <= n; i += 2) {
      cout << i + 1 << " - " << i << " = 1\n";
      cout << "24 * 1 = 24\n";
    }
  } else {
    cout << "2 - 1 = 1\n3 + 1 = 4\n4 * 5 = 20\n20 + 4 = 24\n";
    for (int i = 6; i <= n; i += 2) {
      cout << i + 1 << " - " << i << " = 1\n";
      cout << "24 * 1 = 1\n";
    }
  }
  return 0;
}
