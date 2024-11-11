#include <bits/stdc++.h>
using namespace std;
const int maxn = 400005;
int main() {
  long long n;
  long long mm = 0;
  long long b[200005];
  cin >> n;
  long long w[maxn], u[maxn];
  memset(w, 0, sizeof(w));
  memset(u, 0, sizeof(u));
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    if (i - b[i] >= 0) {
      w[i - b[i]] += b[i];
    } else {
      u[b[i] - i] += b[i];
    }
  }
  for (long long i = 1; i <= maxn - 2; i++) {
    if (mm < w[i]) mm = w[i];
    if (mm < u[i]) mm = u[i];
  }
  cout << mm << endl;
  return 0;
}
