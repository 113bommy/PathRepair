#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k, a, M;
  cin >> n >> m;
  vector<long long> used(n + 1, -1);
  for (long long i = 1; i <= m; i++) {
    long long M = -1;
    for (long long j = 1; j <= n; j++) {
      cin >> a;
      if (a > M) {
        M = a;
        k = j;
      }
    }
    used[k] += M;
  }
  M = -1;
  for (long long i = 1; i <= n; i++) {
    if (used[i] > M) {
      M = used[i];
      k = i;
    }
  }
  cout << k;
}
