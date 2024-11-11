#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long t[n], a[n], b[n];
  vector<long long> ali, bob, both;
  for (long long i = 0; i < n; i++) {
    cin >> t[i] >> a[i] >> b[i];
    if (a[i] == 1 && b[i] == 1) both.push_back(t[i]);
    if (a[i] == 1 && b[i] == 0) ali.push_back(t[i]);
    if (a[i] == 0 && b[i] == 1) bob.push_back(t[i]);
  }
  sort(ali.begin(), ali.end());
  sort(bob.begin(), bob.end());
  sort(both.begin(), both.end());
  long long mini = 300000;
  long long x = both.size();
  long long y = ali.size();
  long long z = bob.size();
  long long m = max(k - z, k - y);
  if (x + y < k || x + z < k)
    cout << "-1\n";
  else {
    for (long long i = max(m, 0ll); i <= min(x, k); i++) {
      long long sum = 0;
      for (long long j = 0; j < i; j++) {
        sum += both[j];
      }
      for (long long j = 0; j < k - i; j++) {
        sum += ali[j];
        sum += bob[j];
      }
      mini = min(mini, sum);
    }
    cout << mini << "\n";
  }
}
