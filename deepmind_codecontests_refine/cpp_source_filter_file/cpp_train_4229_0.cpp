#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = 3.1415926535897932384626433832795;
const long long MAX = 2e5 + 10;
const long long NMAX = 2e5 + 10;
const long long MMAX = 2e5 + 10;
inline void maxn(long long& val, long long newVal) { val = max(val, newVal); }
inline void minn(long long& val, long long newVal) { val = min(val, newVal); }
string str;
long long n, m, k, t, a, b, sc;
const long long N = 1e5 + 5;
long long arr[N];
void solve() {
  cin >> n >> k;
  vector<pair<long long, long long> > anim(n);
  long long totalEx = 0;
  for (long long i = 0, _n = (n); i < _n; i = i + 1) {
    cin >> t;
    totalEx += t;
    anim[i] = {t, i + 1};
  }
  if (totalEx < k) {
    cout << -1 << '\n';
    return;
  }
  sort((anim).begin(), (anim).end());
  long long cur = 0;
  long long lastCnt = 0;
  while (cur < n && k) {
    long long queueSz = n - cur;
    long long toSub = queueSz * (anim[cur].first - lastCnt);
    if (toSub <= k) {
      k -= toSub;
      lastCnt = anim[cur].first;
      cur = upper_bound((anim).begin(), (anim).end(),
                        make_pair((anim[cur].first), (INFLL))) -
            anim.begin();
    } else {
      break;
    }
  }
  for (long long i = (cur), _b = (n); i < _b; i = i + 1)
    swap(anim[i].first, anim[i].second);
  sort(anim.begin() + cur, anim.end());
  if (cur == n) {
    cout << '\n';
    return;
  }
  queue<long long> ans1;
  queue<long long> ans2;
  long long numToRmv = k / (n - cur) + k % (n - cur) > 0;
  numToRmv += lastCnt;
  k = k % (n - cur);
  for (long long i = (cur), _b = (n); i < _b; i = i + 1) {
    bool canRemove = k > 0 && anim[i].second == numToRmv;
    k--;
    if (canRemove) continue;
    if (k < 0)
      ans1.push(anim[i].first);
    else
      ans2.push(anim[i].first);
  }
  while (ans1.empty() == false) {
    cout << ans1.front() << ' ';
    ans1.pop();
  }
  while (ans2.empty() == false) {
    cout << ans2.front() << ' ';
    ans2.pop();
  }
  cout << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long T = 1;
  sc = 1;
  while (T--) {
    solve();
    sc++;
  }
  return 0;
}
