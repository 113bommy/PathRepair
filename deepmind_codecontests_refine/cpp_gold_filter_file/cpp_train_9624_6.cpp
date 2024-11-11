#include <bits/stdc++.h>
using namespace std;
long long n, m, k, ans1 = 0, ans2 = 0;
int main(int argc, const char* argv[]) {
  cin >> n >> m >> k;
  if ((n - 1) + (m - 1) < k) {
    cout << -1 << endl;
    return 0;
  }
  ans1 = n / (min(n - 1, k) + 1);
  if (min(n - 1, k) == k)
    ans1 *= m;
  else
    ans1 *= (m / (k - (n - 1) + 1));
  ans2 = m / (min(m - 1, k) + 1);
  if (min(m - 1, k) == k)
    ans2 *= n;
  else
    ans2 *= (n / (k - (m - 1) + 1));
  cout << max(ans1, ans2) << endl;
  return 0;
}
