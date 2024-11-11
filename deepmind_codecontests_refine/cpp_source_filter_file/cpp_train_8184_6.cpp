#include <bits/stdc++.h>
using namespace std;
const long maxn = 10005;
long long mas[maxn];
long long n, m, k, choice, q;
int main() {
  cin >> n >> m >> k;
  for (q = 1; q <= n; q++) cin >> mas[q];
  long long con = m / (n / 2 + 1);
  if (n % 2 == 0) {
    printf("0");
    return 0;
  }
  long long best = 0;
  for (choice = 1; choice <= n; choice++) {
    long long now = choice - 2;
    long long limit = min(mas[choice], con * k);
    while (now >= 1) {
      limit = min(limit, mas[now]);
      now -= 2;
    }
    now = choice + 2;
    while (now <= n) {
      limit = min(limit, mas[now]);
      now += 2;
    }
    best = max(best, limit);
  }
  cout << best;
}
