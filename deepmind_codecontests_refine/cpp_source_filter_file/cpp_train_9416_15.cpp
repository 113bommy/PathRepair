#include <bits/stdc++.h>
using namespace std;
int n;
int m, w;
long long a[100000 + 1];
long long test(long long mid) {
  long long b[100000 + 1];
  long long c[n + 1];
  long long ee = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    c[i] = 0;
    b[i] = a[i];
  }
  for (int i = 0; i < n; i++) {
    ee -= c[i];
    b[i] += (ee);
    if (b[i] < mid) {
      ans += (mid - b[i]);
      c[i + w] = (mid - b[i]);
      ee += mid - b[i];
    }
  }
  return (ans <= m);
}
int main(int argc, char const *argv[]) {
  cin >> n >> m >> w;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long low = 1, high = 10000000000;
  while (low < high) {
    long long mid = (low + (high - low + 1) / 2);
    long long te = test(mid);
    if (te == 0)
      high = mid - 1;
    else
      low = mid;
  }
  cout << low << "\n";
  return 0;
}
