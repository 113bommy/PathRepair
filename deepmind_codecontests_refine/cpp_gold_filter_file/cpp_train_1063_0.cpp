#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
long long t, n, m, p, f, sum;
long long mx[MAXN][2];
priority_queue<int> Q;
int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    sum = (1 + n) * n / 2;
    p = (n - m) / (m + 1);
    f = (n - m) % (m + 1);
    sum = sum - p * (p + 1) / 2 * (m + 1) - (p + 1) * f;
    cout << sum << endl;
  }
  return 0;
}
