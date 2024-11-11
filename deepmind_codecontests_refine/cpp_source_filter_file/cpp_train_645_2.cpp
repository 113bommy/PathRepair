#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 29;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
long long int a[200005], cost[200005];
int main() {
  multiset<long long int> num;
  map<long long int, vector<long long int> > mp;
  set<long long int> indices;
  long long int n;
  long long int ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    indices.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
    mp[a[i]].push_back(cost[i]);
  }
  long long int ind = *indices.begin();
  long long int sum = 0;
  while (!num.empty() || ind < *indices.rbegin()) {
    if (mp.find(ind) != mp.end())
      for (auto i = mp[ind].begin(); i != mp[ind].end(); i++)
        num.insert(*i), sum += *i;
    sum -= *num.rbegin();
    ans += sum;
    auto k = num.end();
    k--;
    num.erase(k);
    if (num.empty() && ind < *indices.rbegin()) {
      ind = *indices.upper_bound(ind);
      continue;
    }
    ind++;
  }
  cout << ans;
}
