#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> vec(n);
  for (long long i = 0; i < n; i++) {
    cin >> vec[i];
  }
  sort(vec.begin(), vec.end());
  long long count = 0;
  long long current_val = 0;
  for (long long i = 0; i < n; i++) {
    if (vec[i] == 0) continue;
    if (vec[i] != current_val) {
      count++;
      current_val = vec[i];
    }
  }
  cout << count;
  return 0;
}
