#include <bits/stdc++.h>
const long long inf = 0x3f3f3f3f3f3f3f3LL;
const long long mod = (long long)1e9 + 7;
using namespace std;
template <class T>
void smin(T& a, T val) {
  if (a > val) a = val;
}
template <class T>
void smax(T& a, T val) {
  if (a < val) a = val;
}
const long long N = 2 * (long long)1e5 + 10;
long long n, a[N], T, p[N];
vector<pair<long long, long long> > v;
bool cp(long long L, long long R) { return v[L].first < v[R].first; }
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> T;
  v.resize(n);
  for (long long i = 0; i < n; ++i) {
    cin >> v[i].second >> v[i].first;
    p[i] = i;
  }
  sort(p, p + n, cp);
  long long low = 0, high = n, ans = -1;
  while (low <= high) {
    long long score = (low + high) >> 1;
    long long vals = T, problems = 0;
    for (long long i = 0; i < n; ++i) {
      if (problems < score and vals >= v[p[i]].first and
          score <= v[p[i]].second) {
        vals -= v[p[i]].first;
        ++problems;
      }
      if (problems == score) break;
    }
    if (problems == score) {
      ans = score;
      low = score + 1;
    } else {
      high = score - 1;
    }
  }
  cout << ans << '\n';
  cout << ans << '\n';
  long long vals = T, problems = 0, score = ans;
  for (long long i = 0; i < n; ++i) {
    if (problems < ans and vals >= v[i].first and score <= v[p[i]].second) {
      cout << p[i] + 1 << ' ';
      vals -= v[p[i]].first;
      ++problems;
    }
    if (problems == ans) break;
  }
  return 0;
}
