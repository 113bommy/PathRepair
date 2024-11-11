#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433832795l;
template <typename T>
inline auto sqr(T x) -> decltype(x * x) {
  return x * x;
}
template <typename T1, typename T2>
inline bool umx(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool umn(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int N = 110;
const int K = 34000;
int n;
long long k;
int a[N];
vector<pair<int, int> > ord;
int lst_step[N];
long long lst_st[N];
int main() {
  cout.setf(ios::showpoint | ios::fixed);
  cout.precision(20);
  cin >> n >> k;
  for (int i = int(0); i < int(n); ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int d = int(1); d < int(K); ++d) {
    long long sum = 0;
    for (int j = int(0); j < int(n); ++j) {
      sum += (d - a[j] % d) % d;
    }
    if (sum <= k) {
      ans = d;
    }
  }
  for (int kol = int(K) - 1; kol >= int(1); --kol) {
    for (int i = int(0); i < int(n); ++i) {
      if (a[i] >= kol * kol) ord.push_back(make_pair(a[i] / kol + 1, i));
    }
  }
  sort((ord).begin(), (ord).end());
  ord.erase(unique((ord).begin(), (ord).end()), ord.end());
  long long totst = 0, totstep = 0;
  ;
  for (int i = int(0); i < int(((int)(ord).size())); ++i) {
    ;
    ;
    int d = ord[i].first, idx = ord[i].second;
    int st = (d - a[idx] % d) % d;
    int step = (a[idx] + d - 1) / d;
    long long tot = st - 1ll * step * d;
    totst -= lst_st[idx];
    lst_st[idx] = tot;
    totst += lst_st[idx];
    totstep -= lst_step[idx];
    lst_step[idx] = step;
    totstep += lst_step[idx];
    long long nxt = ((i + 1 == ((int)(ord).size())) ? ((long long)2e11 + 1)
                                                    : (ord[i + 1].first));
    long long l = d, r = nxt - 1;
    while (l < r) {
      long long m = (l + r + 1) >> 1;
      if (totst + m * totstep <= k) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    if (l >= K && totst + l * totstep <= k) {
      umx(ans, l);
    };
    ;
    ;
    ;
  }
  cout << ans << endl;
  return 0;
}
