#include <bits/stdc++.h>
using namespace std;
long long int max(long long int a, long long int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long int min(long long int a, long long int b) {
  if (a < b)
    return a;
  else
    return b;
}
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int k, i, j, a, b, l, r, x, n, y, m, c;
  cin >> n >> m >> k;
  long long int low = 1, high = m, ind = 1;
  while (low <= high) {
    long long int mid = (low + high) >> 1;
    a = mid - 1;
    long long int noe = a;
    long long int an = a + (noe - 1) * (-1);
    long long int sum = 0;
    if (a < (n - k)) {
      sum += (n - k) - a;
      noe = a;
    } else
      noe = n - k;
    sum += (noe * (2 * a + (noe - 1) * (-1))) / 2;
    if (a < (k - 1)) {
      sum += (k - 1) - a;
      noe = a;
    } else
      noe = k - 1;
    sum += (noe * (2 * a + (noe - 1) * (-1))) / 2;
    sum += mid;
    if (m >= sum) {
      ind = mid;
      low = mid + 1;
    } else
      high = mid - 1;
  }
  cout << ind << "\n";
}
