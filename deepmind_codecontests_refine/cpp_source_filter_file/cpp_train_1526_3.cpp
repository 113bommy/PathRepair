#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b;
  cin >> n >> a >> b;
  long long r = static_cast<long long int>(log2(n));
  long long an = 1;
  long long c = min(a, b);
  b = max(a, b);
  a = c;
  a -= 1;
  b -= 1;
  while (an <= r) {
    if (a + 1 == b) {
      if (an == r) {
        cout << "Final!";
      } else
        cout << an;
      return 0;
    } else {
      a /= 2;
      b /= 2;
      an++;
    }
  }
  cout << "Final!";
  return 0;
}
