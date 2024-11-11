#include <bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
const long long MOD1 = 10e9 + 7;
const long long MOD2 = 10e9 + 9;
const long long MOD3 = 2 * 10e9 + 11;
const long long INF = LLONG_MAX;
long long n, k;
vector<pair<long long, long long> > answer;
bool check(long long t) {
  long long ans = 0;
  for (auto i : answer) {
    ans += i.first / t;
  }
  return (ans >= k);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(20);
  srand(time(0));
  cin >> n >> k;
  vector<long long> vec(n);
  vector<pair<long long, long long> > a(2 * 100 * 1000 + 100, {0, 0});
  long long ptr = 0;
  for (long long i = 0; i < n; i++) {
    cin >> vec[i];
    a[vec[i]].second = vec[i];
    if (a[vec[i]].first == 0) {
      ptr++;
    }
    a[vec[i]].first++;
  }
  for (long long i = 0; i < 200100; i++) {
    if (a[i].first) {
      answer.push_back({a[i].first, a[i].second});
    }
  }
  sort((answer).rbegin(), (answer).rend());
  long long l = 1;
  long long r = n + 1;
  while (r > l) {
    long long m = (l + r) >> 1;
    if (check(m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  r--;
  vector<long long> viv;
  for (long long i = 0; i < ptr; i++) {
    for (long long j = 0; j < (answer[i].first / r); j++) {
      viv.push_back(answer[i].second);
    }
  }
  for (long long i = 0; i < k; i++) {
    cout << i << ' ';
  }
  return 0;
}
