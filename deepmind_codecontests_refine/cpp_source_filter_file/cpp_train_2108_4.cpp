#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  std::ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    long long n;
    cin >> n;
    int days = 1;
    while ((1LL << (days + 1)) - 1 < n) ++days;
    long long rem = n - (1LL << days) + 1;
    vector<long long> res;
    res.reserve(days + 1);
    res.push_back(1);
    for (int p = 1; p < days; ++p) {
      if (rem > res.back() && rem <= (1LL << p)) {
        res.push_back(rem);
      }
      res.push_back(1LL << p);
    }
    if (res.size() == days) {
      res.push_back(rem);
    }
    cout << days << endl;
    for (int i = 1; i <= days; ++i) {
      cout << res[i] - res[i - 1] << ' ';
    }
    cout << endl;
  }
  return 0;
}
