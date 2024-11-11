#include <bits/stdc++.h>
using namespace std;
const int Z = (int)2e4 + 228;
const int N = (int)3e5 + 228;
const int INF = (int)1e18 + 228;
const int MOD = (int)1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "YES\n" << n;
    return 0;
  }
  long long sum = (1 + k) * 1LL * k / 2;
  if (sum > n) {
    cout << "NO";
    return 0;
  }
  vector<int> a(k);
  for (int i = 0; i < k; i++) a[i] = i + 1;
  int ost = n - sum;
  for (int i = 0; i < k; i++) a[i] += ost / k;
  ost %= k;
  for (int i = k - 1; i >= 0 && ost; i--, ost--) a[i]++;
  if (a[0] == 1 && a[0] != 2) {
    a[k - 1]++;
    a[1]--;
  }
  for (int i = 1; i < k; i++)
    if (a[i] > a[i - 1] + a[i - 1]) {
      cout << "NO";
      return 0;
    }
  cout << "YES\n";
  for (int i : a) cout << i << ' ';
  return 0;
}
