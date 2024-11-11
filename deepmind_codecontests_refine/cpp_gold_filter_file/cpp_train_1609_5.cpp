#include <bits/stdc++.h>
using namespace std;
long long const delta = 1000000007;
vector<long long> primes;
long long mark[(long long)1e5 + 8];
long long mark2[(long long)1e5 + 8];
void pre(long long n) {
  for (long long i = 2; i <= n / 2; i++) {
    if (mark[i]) continue;
    primes.push_back(i);
    ;
    for (long long j = 2 * i; j <= n / 2; j += i) mark[j] = 1;
  }
}
int main() {
  std::ios::sync_with_stdio(0);
  ;
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  pre(n);
  vector<pair<long long, long long> > ans;
  vector<long long> tof;
  vector<long long> temp;
  if (n <= 3) return cout << 0, 0;
  for (long long i = primes.size() - 1; i >= 0; i--) {
    temp.clear();
    long long a = primes[i];
    for (long long j = 1; j * primes[i] <= n; j++) {
      if (j == 2) continue;
      if (!mark2[j * primes[i]]) {
        temp.push_back(j * primes[i]);
        ;
      }
    }
    if (temp.size() % 2 == 0) {
      for (long long j = 0; j < temp.size(); j += 2) {
        mark2[temp[j]] = mark2[temp[j + 1]] = 1;
        ans.push_back(make_pair(temp[j], temp[j + 1]));
        ;
      }
      if (!mark2[temp[0] * 2]) {
        tof.push_back(temp[0] * 2);
        ;
        mark2[temp[0] * 2] = 1;
      }
    } else {
      for (long long j = 1; j < temp.size(); j += 2) {
        mark2[temp[j]] = mark2[temp[j + 1]] = 1;
        ans.push_back(make_pair(temp[j], temp[j + 1]));
        ;
      }
      mark2[temp[0]] = mark2[temp[0] * 2] = 1;
      ans.push_back(make_pair(temp[0], temp[0] * 2));
      ;
    }
  }
  for (long long i = 0; i < tof.size(); i += 2) {
    if (i + 1 < tof.size()) ans.push_back(make_pair(tof[i], tof[i + 1]));
    ;
  }
  cout << ans.size() << endl;
  for (long long i = 0; i < ans.size(); i++)
    cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
