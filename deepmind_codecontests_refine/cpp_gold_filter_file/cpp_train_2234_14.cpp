#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int N = (int)(5 * 1e5 + 10);
long long test, n, query, q, k, value, m, x, val, a, b, c, left_index,
    right_index, sum;
int main() {
  clock_t tStart = clock();
  scanf("%lld", &n), scanf("%lld", &x);
  long long min = (n / 2) + (n % 2);
  if (min % x == 0) {
    cout << min << "\n";
  } else {
    long long needs = x - (min % x);
    if (needs > (n / 2)) {
      cout << "-1\n";
    } else {
      cout << min + needs << "\n";
    }
  }
  return 0;
}
