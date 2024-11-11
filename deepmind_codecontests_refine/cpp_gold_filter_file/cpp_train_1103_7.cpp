#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e5 + 5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long k;
  string n;
  cin >> k;
  cin >> n;
  long long sn = n.size();
  long long sum = 0;
  for (__typeof(sn - 1) i = 0; i <= sn - 1; ++i) sum += (int)(n[i] - '0');
  long long bit = 0, tsum = sum;
  if (sum >= k)
    cout << "0\n";
  else {
    string tn = n;
    sort(tn.begin(), tn.end());
    long long stn = tn.size();
    for (__typeof(stn - 1) i = 0; i <= stn - 1; ++i) {
      tsum = sum;
      sum += 9 - (int)(tn[i] - '0');
      if (tsum != sum) ++bit;
      if (sum >= k) break;
    }
    cout << bit << "\n";
  }
  return 0;
}
