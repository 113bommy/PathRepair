#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  long long n, o = 0, x;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> x;
    if (x % 2) o++;
  }
  cout << min(o, n - o) + (o - min(o, n - o)) / 3;
  return 0;
}
