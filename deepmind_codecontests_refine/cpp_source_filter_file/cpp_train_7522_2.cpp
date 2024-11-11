#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, n, val;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long int> v(n);
    for (i = 0; i < n; i++) cin >> v[i];
    long long int negsum = 0;
    long long int negcount = 0;
    long long int x = 0;
    for (i = n - 1; i >= 0; i--) {
      if (v[i] < 0)
        negsum += abs(v[i]);
      else if (v[i] > 0) {
        val = v[i];
        negcount += min(v[i], negsum);
        v[i] = max(x, v[i] - negsum);
        negsum = max(negsum - val, x);
      }
    }
    for (i = n - 1; i >= 0; i--) {
      if (v[i] < 0 && negcount > 0) {
        val = v[i];
        if (abs(v[i]) <= negcount)
          v[i] = 0;
        else
          v[i] = v[i] + negcount;
        negcount = abs(max(val + negcount, x));
      }
    }
    long long int posval = 0;
    for (i = 0; i < n; i++) {
      if (v[i] > 0) posval += v[i];
    }
    cout << posval;
  }
}
