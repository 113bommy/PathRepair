#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn], b[maxn];
bool cmp(long long a, long long b) { return a > b; }
int main() {
  long long n, k, t;
  cin >> n >> k >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b + n - 1, cmp);
  long long sum = 0;
  for (long long i = 0; i < k - 1; i++) sum += b[i];
  for (long long i = 0; i < n; i++) {
    if (a[i] >= b[k - 1]) {
      if (sum + b[k - 1] > t) {
        cout << i + 1 << endl;
        return 0;
      }
    } else {
      if (a[i] + sum > t) {
        cout << i + 1 << endl;
        return 0;
      }
    }
  }
  cout << n << endl;
  return 0;
}
