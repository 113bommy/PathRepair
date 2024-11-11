#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  string ar;
  long long k, n;
  cin >> ar >> k;
  n = ar.size();
  for (long long i = 0; i < n; i++) {
    pair<char, long long> mn = {0, -1};
    for (long long j = i + 1, swaps = 0; j < n && swaps < k; swaps++, j++) {
      if (mn.first < ar[j]) mn = {ar[j], j};
    }
    if (mn.second == -1 || ar[i] >= mn.first) continue;
    k -= mn.second - i;
    ar.erase(ar.begin() + mn.second);
    ar.insert(ar.begin() + i, mn.first);
  }
  cout << ar << "\n";
  return 0;
}
