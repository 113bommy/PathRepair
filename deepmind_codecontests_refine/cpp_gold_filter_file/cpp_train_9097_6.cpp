#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const long long int INF = 1000 * 1000 * 1000 * 1000 * 1000 * 100;
long long int p[50];
int main() {
  p[1] = 3LL;
  int cnt = 1;
  for (long long int i = 2;; i++) {
    if (p[i - 1] * 3LL > (1e18)) break;
    p[i] = p[i - 1] * 3LL;
    cnt++;
  }
  long long int N;
  while (cin >> N) {
    long long int ans = 0;
    int mini = 1;
    for (int i = 1; i <= cnt; i++) {
      if (N % p[i] != 0) {
        mini = i;
        break;
      }
    }
    ans = N / p[mini];
    cout << ans + 1 << endl;
  }
  return 0;
}
