#include <bits/stdc++.h>
using namespace std;
const long long mx = 2e5 + 5;
long long n, a, b, c;
int main() {
  cin >> a >> b >> c;
  int maxx;
  maxx = max(a, b);
  int maxxx = maxx;
  if (c > maxx) {
    maxx = c;
  }
  int sum = a + b + c - maxx;
  if (sum > maxx) {
    cout << 0;
  } else {
    cout << abs(sum - maxx) + 1;
  }
  return 0;
}
