#include <bits/stdc++.h>
using namespace std;
vector<bool> prime(200002, true);
void seive(long long mx) {
  prime[0] = prime[1] = false;
  for (long long i = 2; i * i <= mx; i++) {
    if (prime[i]) {
      for (long long j = i * i; j <= mx; j += i) {
        prime[j] = false;
      }
    }
  }
}
const long long M = 1e9 + 7;
const long long Mxn = 3e5;
long long power(long long i, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * i) % M;
    i = (i * i) % M;
    p /= 2;
  }
  return ans % M;
}
int main() {
  int t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long arr[m][n];
    unordered_set<long long> st, ans;
    for (long long i = 0; i < m; i++) {
      for (long long j = 0; j < n; j++) cin >> arr[i][j];
    }
    for (long long i = 0; i < n; i++) st.insert(i);
    for (long long i = 0; i < n - 1; i++) {
      vector<pair<long long, long long> > v;
      unordered_set<long long> s;
      int lll = 0, rr = 0;
      for (long long j = 0; j < m; j++) {
        v.push_back({arr[j][n - 1] - arr[j][i], j});
        lll += arr[j][i];
        rr += arr[j][n - 1];
      }
      int pp = lll - rr;
      if (pp >= 0) {
        cout << "0";
        return 0;
      }
      sort(v.rbegin(), v.rend());
      for (long long j = 0; j < m; j++) {
        pp += v[j].first;
        s.insert(v[j].second);
        if (pp >= 0) break;
      }
      if (s.size() <= st.size()) st = s;
    }
    cout << st.size() << endl;
    for (auto i : st) cout << i + 1 << " ";
    cout << endl;
  }
  return 0;
}
