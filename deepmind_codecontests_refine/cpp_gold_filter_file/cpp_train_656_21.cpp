#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 10e4;
const long long mn = 0;
const long long mx = 10e17;
map<string, long long> mp;
long long ans, n, k, m, cnt;
vector<long long> dp, v, v1;
deque<long long> dq;
queue<long long> qe;
string s, a, d;
set<string> st;
int main() {
  ios_base::sync_with_stdio(0);
  ;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> m;
    ans += (i * m);
  }
  cout << ans;
}
