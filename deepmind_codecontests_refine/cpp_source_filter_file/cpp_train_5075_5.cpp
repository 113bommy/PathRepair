#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, b;
  cin >> n >> b;
  long long temp = 0, ct1 = 0, ct2 = 0;
  long long a[n];
  vector<long long> v;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; ++i) {
    if (a[i] % 2)
      ct1++;
    else
      ct2++;
    if (i && (ct1 == ct2) && i < n - 1) {
      v.push_back(abs(a[i] - a[i + 1]));
    }
  }
  sort(v.begin(), v.end());
  long long t = 0;
  for (long long i = 0; i < v.size(); ++i) {
    if (t + v[i] < b) {
      temp++;
      t += v[i];
    }
  }
  cout << temp << "\n";
  return 0;
}
