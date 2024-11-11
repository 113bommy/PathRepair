#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long n, i;
  cin >> i >> n;
  long long a1[n], a2[n];
  for (i = 0; i < n; i++) {
    cin >> a1[i];
  }
  map<long long, long long> val;
  long long k = 1;
  for (i = 0; i < n; i++) {
    cin >> a2[i];
    val[a2[i]] = k;
    k++;
  }
  long long mxval = 0;
  long long ans = 0;
  for (i = 0; i < n; i++) {
    if (val[a1[i]] < mxval) {
      ans++;
    }
    mxval = max(mxval, val[a1[i]]);
  }
  cout << ans << "\n";
}
