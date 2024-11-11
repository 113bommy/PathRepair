#include <bits/stdc++.h>
using namespace std;
bool myway(const pair<long long, long long> &p1,
           const pair<long long, long long> &p2) {
  if (p1.first == p2.first) return p1.second < p2.second;
  return p1.first > p2.first;
}
int main() {
  int n;
  long long s;
  cin >> n >> s;
  long long cost[n];
  for (int i = 0; i < n; i++) cin >> cost[i];
  int l = 0, r = n;
  vector<pair<long long, long long> > st;
  while (l <= r) {
    int k = (l + r) / 2;
    long long a[n];
    for (int i = 0; i < n; i++) a[i] = cost[i] + (i + 1) * k;
    sort(a, a + n);
    long long sum = 0;
    int i = 0;
    for (i = 0; i < k; i++) sum += a[i];
    if (sum > s) {
      r = k - 1;
    } else {
      st.push_back({(long long)k, sum});
      l = k + 1;
    }
  }
  sort(st.begin(), st.end(), myway);
  cout << (st.begin())->first << " " << (st.begin())->second << "\n";
}
