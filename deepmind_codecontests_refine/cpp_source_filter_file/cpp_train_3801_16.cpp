#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long x;
  cin >> x;
  vector<pair<unsigned long long, unsigned long long> > res;
  for (unsigned long long n = 1; n <= 1000000 + 100000; n++) {
    if ((6 * x) % (n * (n + 1)) == 0 &&
        (6 * x / (n * (n + 1)) + n - 1) % 3 == 0) {
      unsigned long long m = (6 * x / (n * (n + 1)) + n - 1) / 3;
      if (m >= n) {
        res.push_back({n, m});
        res.push_back({m, n});
      }
    }
  }
  sort(res.begin(), res.end());
  int cur = (int)res.size();
  for (int i = 1; i < (int)res.size(); i++)
    if (res[i] == res[i - 1]) cur--;
  cout << cur << endl;
  for (int i = 0; i < (int)res.size(); i++) {
    if (!i)
      cout << res[i].first << " " << res[i].second << endl;
    else if (i && res[i] != res[i - 1])
      cout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}
