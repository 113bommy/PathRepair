#include <bits/stdc++.h>
using namespace std;
long long a[300000];
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  long long n, k;
  cin >> n >> k;
  {
    for (unsigned long long _ = 0; _ < n; ++_) cin >> (a)[_];
  };
  long long c = 0;
  for (long long i = 1; i < n; ++i) {
    c += a[i] - a[i - 1];
    a[i - 1] = a[i] - a[i - 1];
  }
  sort(a, a + n - 1, greater<long long>());
  for (long long i = 0; i < k - 1; ++i) c -= a[i];
  cout << c << endl;
  return 0;
}
