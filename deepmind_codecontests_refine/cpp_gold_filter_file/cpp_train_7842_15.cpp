#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  long long k, b, n, t;
  cin >> k >> b >> n >> t;
  int res = n + 1;
  long long ttt = 1;
  while (ttt <= t && res > 0) {
    ttt = k * ttt + b;
    res--;
  }
  cout << res << endl;
  return 0;
}
