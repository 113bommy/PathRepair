#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> A(n);
  for (long long i = 0; i < n; i++) cin >> A[i];
  map<long long, vector<pair<long long, long long>>> M;
  for (long long i = 0; i < n; i++) {
    long long s = 0;
    for (long long j = i; j < n; j++) {
      s += A[j];
      M[s].push_back({j, i});
    }
  }
  vector<pair<long long, long long>> Ans;
  for (auto &it : M) {
    sort(it.second.begin(), it.second.end());
    long long e = -1;
    vector<pair<long long, long long>> c;
    for (long long i = 0; i < (long long)it.second.size(); i++) {
      long long r = it.second[i].first;
      long long l = it.second[i].second;
      if (l > e) {
        c.push_back({l, r});
        e = max(e, r);
      }
    }
    if (Ans.size() <= c.size()) Ans = c;
  }
  cout << Ans.size() << '\n';
  for (long long i = 0; i < (long long)Ans.size(); i++)
    cout << Ans[i].first + 1 << " " << Ans[i].second + 1 << '\n';
}
