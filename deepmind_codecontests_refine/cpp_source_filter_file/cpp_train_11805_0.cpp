#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;
int test = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  ;
  long long n, m, k, ma = 0, mb = 0, sum1 = 0, sum2 = 0, mib = INT_MAX,
                     mia = INT_MAX;
  cin >> n >> m >> k;
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a.push_back(x);
    sum1 += x;
    if (ma < x) ma = x;
    if (mia > x) mia = x;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    b.push_back(x);
    sum2 += x;
    if (mb < x) mb = x;
    if (mib > x) mib = x;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int j = m - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > b[j]) {
      cout << "YES" << endl;
      exit(0);
    } else if (a[i] <= b[i]) {
      j--;
      continue;
    }
  }
  cout << "NO" << endl;
}
