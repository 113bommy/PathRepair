#include <bits/stdc++.h>
using namespace std;
multiset<long long> sugrobs;
long long vv[179179];
long long tt[179179];
int main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> vv[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> tt[i];
  }
  long long sumOfSnow = 0;
  for (int i = 0; i < n; ++i) {
    long long v, t, ans = 0;
    v = vv[i];
    t = tt[i];
    sugrobs.insert(v + sumOfSnow);
    while (true) {
      if (sugrobs.empty()) {
        break;
      }
      long long minSugr = *sugrobs.begin();
      if (minSugr <= sumOfSnow + t) {
        ans += minSugr - sumOfSnow;
        sugrobs.erase(sugrobs.find(minSugr));
      } else {
        break;
      }
    }
    sumOfSnow += t;
    ans += t * sugrobs.size();
    cout << ans << " ";
  }
}
