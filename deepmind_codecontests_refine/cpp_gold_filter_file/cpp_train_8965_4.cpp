#include <bits/stdc++.h>
using namespace std;
long long int next(long long int v) {
  long long int t = v | (v - 1);
  return (t + 1) | (((~t & -~t) - 1) >> (__builtin_ctz(v) + 1));
}
std::vector<long long int> filter(std::vector<long long int>& v,
                                  long long int mask) {
  std::vector<long long int> res;
  while (mask) {
    res.push_back(v[__builtin_ctz(mask)]);
    mask &= mask - 1;
  }
  return res;
}
std::set<std::vector<long long int>> get_subsets(std::vector<long long int> arr,
                                                 long long int k) {
  std::set<std::vector<long long int>> second;
  long long int max = (1 << arr.size());
  for (long long int v = (1 << k) - 1; v < max; v = next(v)) {
    second.insert(filter(arr, v));
  }
  return second;
}
long long compute_hash(string second) {
  const int p = 31;
  const int m = 1e9 + 9;
  long long hash_value = 0;
  long long p_pow = 1;
  for (char c : second) {
    hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
    p_pow = (p_pow * p) % m;
  }
  return hash_value;
}
map<long long int, long long int> has;
signed main() {
  std::ios::sync_with_stdio(false);
  long long int t;
  cin >> t;
  while (t--) {
    long long int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    vector<long long int> v, v2;
    v.push_back(l1);
    v.push_back(r1);
    v2.push_back(l2);
    v2.push_back(r2);
    bool poss = false;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        if (v[i] != v2[j]) {
          cout << v[i] << " " << v2[j] << "\n";
          poss = true;
          break;
        }
      }
      if (poss) break;
    }
    if (poss) continue;
    cout << l1 << " " << l2 + 1 << "\n";
  }
}
