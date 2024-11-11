#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, b, j, c, i, n, d, k, cnt = 0, sum = 0, mi = INT_MIN,
                                        flag1 = 0, flag2 = 0;
  string s;
  cin >> n;
  for (i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n % i == i)
        cnt++;
      else
        cnt += 2;
    }
  }
  cout << cnt - 1;
  return 0;
}
