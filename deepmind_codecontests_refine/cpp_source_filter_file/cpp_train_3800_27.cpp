#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int sq = sqrt(x);
  int count1 = 0, count2 = 0;
  for (int i = 1; i <= sq; i++) {
    if (x % i == 0 && (i <= n && (x / i) <= n)) {
      if (i != n / i)
        count1++;
      else
        count2++;
    }
  }
  cout << 2 * count1 + count2;
}
