#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k, i, j, capacity = 0, increment;
  cin >> n >> k;
  long long aim[n];
  capacity = 0;
  for (i = 0; i < n; i++) {
    cin >> aim[i];
    aim[i] -= k;
  }
  cin >> increment;
  long long flag = 0;
  for (i = 0; i < n; i++) {
    if (aim[i] - increment * (i + 1) > 0) {
      flag = -1;
      break;
    }
  }
  if (flag == -1) {
    cout << "-1" << endl;
  } else {
    map<long long, long long> costs;
    long long extra_needed, extra_gained, extra_drinks, diff = 0, ans = 0, temp;
    for (i = 0; i < n; i++) {
      cin >> temp;
      costs[temp]++;
      extra_needed = aim[i];
      diff = extra_needed - capacity;
      if (diff > 0) {
        extra_drinks = (long long)(ceil((double)diff / increment));
        capacity += extra_drinks * increment;
        auto it = costs.begin();
        for (; it != costs.end() && extra_drinks > 0; it++) {
          if ((*it).second > extra_drinks) {
            (*it).second -= extra_drinks;
            ans += extra_drinks * (*it).first;
            extra_drinks = 0;
          } else if ((*it).second <= extra_drinks) {
            extra_drinks -= (*it).second;
            ans += ((*it).second) * ((*it).first);
            (*it).second = 0;
          }
        }
        costs.erase(costs.begin(), it);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
