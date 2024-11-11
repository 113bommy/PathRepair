#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 2;
unordered_map<long long, unordered_map<long long, long long>> BIT;
void update(long long ind, long long t, long long val) {
  while (t < M) {
    BIT[ind][t] += val;
    t += (t & -t);
  }
}
long long soluchan(long long ind, long long t) {
  long long ans = 0;
  while (t > 0) {
    ans += BIT[ind][t];
    t -= (t & -t);
  }
  return ans;
}
void singh() {
  long long n;
  cin >> n;
  while (n--) {
    long long type, t, x;
    cin >> type >> t >> x;
    if (type == 1)
      update(x, t, 1);
    else if (type == 2)
      update(x, t, -1);
    else
      cout << soluchan(x, t) << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    singh();
  }
}
