#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, n, q, p, ck = 0, mk = 0;
  cin >> n;
  long long int cnt = 0;
  if (n % 400 == 0)
    mk = 1;
  else if (n % 4 == 0 && n % 100 != 0)
    mk = 1;
  for (long long int i = n + 1; i < 200000; i++) {
    if (i % 400 == 0) {
      ck = 1;
      cnt += 2;
    } else if (i % 4 == 0 && i % 100 != 0) {
      ck = 1;
      cnt += 2;
    } else {
      cnt++;
      ck = 0;
    }
    if (cnt % 7 == 0 && cnt != 0 && mk == ck) {
      cout << i << endl;
      return 0;
    }
  }
}
