#include <bits/stdc++.h>
const double eps = 1e-10;
using namespace std;
int n, m, k, s;
int so;
int allin, games;
const int N = (100009);
using PII = pair<int, int>;
int main() {
  scanf("%d%d%d", &n, &m, &s);
  long long pas = 0;
  for (int p = 1; p <= n; p += 2) {
    for (int q = 1; q <= n; q += 2) {
      int area = p * q, tmp = (n - p + 1) * (m - q + 1);
      if (area >= s && (area - s) % 4 == 0) {
        area = (area - s) / 4;
        if (area == 0) {
          pas += (1LL) * (tmp) * ((p / 2 + 1) * (q / 2 + 1) * 2 - 1);
        } else {
          for (int a = 1; a <= p / 2; a++) {
            if (area % a == 0 && area / a <= q / 2) {
              pas += (tmp)*2;
            }
          }
        }
      }
    }
  }
  cout << pas << endl;
}
