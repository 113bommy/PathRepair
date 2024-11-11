#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
long long solve();
int main() {
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}
long long solve() {
  long long bit = 0, sum = a[0] + a[1], tmp = 0;
  vector<int> id;
  for (int i = 2; i < n; ++i) bit ^= a[i];
  if ((sum ^ bit) & 1) return -1;
  for (int i = 0; i < 50; ++i)
    if (bit >> i & 1) {
      sum -= 1LL << i;
      id.push_back(i);
    }
  if (sum < 0) return -1;
  for (int i = 1; i < 50; ++i) {
    if ((sum >> i & 1) && (bit >> (i - 1) & 1)) return -1;
    if (sum >> i & 1) tmp += 1LL << (i - 1);
  }
  if (tmp >= a[0]) return -1;
  reverse(id.begin(), id.end());
  for (auto x : id)
    if ((1LL << x) + tmp < a[0]) tmp += 1LL << x;
  if (tmp == 0) return -1;
  return a[0] - tmp;
}
