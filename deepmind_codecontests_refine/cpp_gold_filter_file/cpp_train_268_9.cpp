#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
clock_t time_p = clock();
void aryanc403() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
class CMP {
 public:
  bool operator()(long long int a, long long int b) { return !(a <= b); }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  map<long long int, long long int>::iterator jt;
  jt = m.find(x);
  if (jt == m.end())
    m.insert(make_pair(x, cnt));
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  map<long long int, long long int>::iterator jt;
  jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
const long long int mod = 1000000007L;
long long int T, n, i, j, k, in, cnt, l, r;
long long int m;
string s;
vector<long long int> a;
vector<long long int>::iterator it;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n >> k >> m;
    long long int sum = 0;
    a.clear();
    a.reserve(k);
    for (i = 0; i < (k); ++i) {
      cin >> in;
      a.push_back(in);
      sum += in;
    }
    sort(a.begin(), a.end());
    long long int ans = 0, cnt, min;
    for (j = (0); j <= (n); ++j) {
      cnt = j * (k + 1);
      min = m - j * sum;
      if (min < 0) break;
      for (auto x : a) {
        for (l = (j + 1); l <= (n); ++l) {
          min -= x;
          if (min < 0) break;
          cnt++;
        }
      }
      ans = max(ans, cnt);
    }
    cout << ans << "\n";
  }
  aryanc403();
  return 0;
}
