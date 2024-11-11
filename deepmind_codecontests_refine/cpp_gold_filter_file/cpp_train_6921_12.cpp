#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007LL;
const int MAXN = 10000007;
const int MAX = 1000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, sum, cnt;
  cin >> n;
  vector<long long> v(n);
  for (long long i = (long long)0, asdf = (long long)n; i < asdf; ++i)
    cin >> v[i];
  sort(v.begin(), v.end());
  queue<long long> q;
  for (long long i = (long long)0, asdf = (long long)n; i < asdf; ++i)
    q.push(v[i]);
  sum = cnt = 0LL;
  while (!q.empty()) {
    if (q.front() >= sum) {
      sum += q.front();
      cnt++;
    }
    q.pop();
  }
  cout << cnt << "\n";
  return 0;
}
