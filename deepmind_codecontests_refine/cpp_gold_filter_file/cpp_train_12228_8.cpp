#include <bits/stdc++.h>
using namespace std;
long long a, b, n;
long long sum;
bool pos;
long long saveA, saveB;
long long ans = 2000000000000000000LL;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> a >> b;
  n *= 6;
  if (a > b)
    pos = 1, swap(a, b);
  else
    pos = 0;
  for (long long i = 1; i <= n; ++i) {
    long long l = i, r = (n + i - 1) / i;
    if (l > r) break;
    if (l < a) l = a;
    if (r < b) r = b;
    if (l * r < ans) {
      ans = l * r;
      saveA = l;
      saveB = r;
    }
  }
  if (pos) swap(saveA, saveB);
  cout << ans << endl << saveA << " " << saveB << endl;
  return 0;
}
