#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> vec(n);
  for (int i = 0; i < n; ++i) cin >> vec[i];
  sort(vec.begin(), vec.end());
  vector<int> seta, setb;
  for (int i = 0; i < n; ++i) {
    if (vec[i] == -1) continue;
    auto iter = lower_bound(vec.begin(), vec.end(), vec[i] * k);
    if (iter != vec.end() && *iter == vec[i] * k) {
      seta.push_back(vec[i]);
      setb.push_back(*iter);
      *iter = -1;
    } else {
      seta.push_back(vec[i]);
      setb.push_back(vec[i]);
    }
  }
  cout << max(seta.size(), setb.size());
}
