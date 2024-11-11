#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int m, int M, int d, int D) {
  if (m < M)
    return true;
  else if (m == M)
    return d <= D;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int D, M, Y, d, m, y;
  int f[3] = {0};
  scanf("%d.%d.%d", &D, &M, &Y);
  scanf("%d.%d.%d", &f[0], &f[1], &f[2]);
  sort(f, f + 3);
  do {
    d = f[0], m = f[1], y = f[2];
    if (m > 12) continue;
    if (d > (days[m] + (y % 4 == 0 && m == 2))) continue;
    if (Y - y > 18 || (Y - y == 18 && check(m, M, d, D))) {
      cout << "YES"
           << "\n";
      return 0;
    }
  } while (next_permutation(f, f + 3));
  cout << "NO"
       << "\n";
  return 0;
}
