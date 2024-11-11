#include <bits/stdc++.h>
using namespace std;
double range[100000 + 2];
int count(long long l, long long r, long long p) {
  int lc = l / p;
  if (l % p == 0) lc--;
  int rc = r / p;
  return rc - lc;
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  long long p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    range[i] = double(count(l, r, p)) / (r - l + 1);
  }
  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += 2000 * (1 - (1 - range[i]) * (1 - range[(i + 1) % n]));
  }
  cout << sum << endl;
  return 0;
}
