#include <bits/stdc++.h>
const int mod = 1E9 + 7;
const int intmax = 1E9 + 7;
using namespace std;
int aa[100005];
int bb[100005];
bool comp(int a, int b) { return (a % 10) > (b % 10); }
int main() {
  ios::sync_with_stdio(0);
  int test, a, b, c;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> aa[i];
  sort(aa, aa + n, comp);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int rem = aa[i] % 10;
    rem = 10 - rem;
    int min_ = min(rem, k);
    aa[i] += min_;
    k -= min_;
    sum += aa[i] / 10;
  }
  sum += k / 10;
  if (sum > n * 10)
    cout << n * 10;
  else
    cout << sum;
}
