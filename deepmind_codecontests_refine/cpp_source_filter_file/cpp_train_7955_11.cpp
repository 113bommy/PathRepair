#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using db = double;
int n;
int main() {
  cin >> n;
  if (n == 6) {
    cout <<
        R"fuckyou(1 4 1
4 5 2
5 6 3
2 5 1
3 6 1
1 2
1 3
2 3
)fuckyou";
    return 0;
  }
  int t = n / 2;
  bool even = n % 2 == 0;
  if (even) --n;
  int m = (n - 3) / 2;
  printf("%d %d %d\n", 1, 2, 1);
  printf("%d %d %d\n", 2, m + 3, 1);
  for (int i = 1; i <= m; ++i) {
    printf("%d %d %d\n", i + m + 2, i + m + 3, i + 1);
    printf("%d %d %d\n", i + 2, i + m + 3, 1);
  }
  if (even) printf("%d %d %d\n", n, n + 1, 1);
  for (int i = 1; i <= 2; ++i)
    for (int j = 3; j <= 3 + m - 1; ++j)
      if (t) {
        --t;
        printf("%d %d\n", i, j);
      }
  return 0;
}
