#include <bits/stdc++.h>
using namespace std;
vector<long long> p(100001);
long long fact(long long n) {
  if (n <= 1)
    return 1;
  else
    return (n * fact(n - 1));
}
inline void solve();
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long test;
  test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
class cmp {
 public:
  bool operator()(const pair<long long, long long> &a,
                  const pair<long long, long long> &b) const {
    long long lena = a.second - a.first + 1;
    long long lenb = b.second - b.first + 1;
    if (lena == lenb) return a.first < b.first;
    return lena > lenb;
  }
};
void solve() {
  long long n = 3;
  vector<pair<long long, long long> > v(3);
  long long mina = 1000000007, maxa = 0;
  long long minb = 1000000007, maxb = 0;
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    mina = min(v[i].first, mina);
    maxa = max(v[i].first, maxa);
    minb = min(v[i].second, minb);
    maxb = max(v[i].second, maxb);
  }
  long long ans = maxb - minb + maxa - mina + 1;
  cout << ans << endl;
  sort(v.begin(), v.end());
  if (v[0].first == v[2].first) {
    for (long long i = v[0].second; i <= v[2].second; i++) {
      cout << v[0].first << " " << i << endl;
    }
    return;
  }
  set<pair<long long, long long> > s;
  if ((v[0].second - v[1].second) * (v[0].second - v[2].second) >= 0) {
    for (long long i = v[0].first; i <= v[1].first; i++) {
      s.insert({i, v[0].second});
    }
    if (v[0].second >= v[1].second) {
      for (long long i = v[0].second; i >= v[1].second; i--) {
        s.insert({v[1].first, i});
      }
    } else {
      for (long long i = v[0].second; i <= v[1].second; i++) {
        s.insert({v[1].first, i});
      }
    }
    if (v[2].second >= v[1].second && v[1].second >= v[0].second) {
      for (long long i = v[1].first; i <= v[2].first; i++) {
        s.insert({i, v[1].second});
      }
      for (long long i = v[1].second; i <= v[2].second; i++) {
        s.insert({v[2].first, i});
      }
    } else if (v[2].second >= v[1].second && v[1].second <= v[0].second) {
      for (long long i = v[1].first; i <= v[2].first; i++) {
        s.insert({i, v[2].second});
      }
    } else if (v[2].second <= v[1].second && v[1].second <= v[0].second) {
      for (long long i = v[1].first; i <= v[2].first; i++) {
        s.insert({i, v[1].second});
      }
      for (long long i = v[1].second; i >= v[2].second; i--) {
        s.insert({v[2].first, i});
      }
    } else if (v[2].second <= v[1].second && v[1].second >= v[0].second) {
      for (long long i = v[1].first; i <= v[2].first; i++) {
        s.insert({i, v[2].second});
      }
    }
  } else {
    for (long long i = v[0].first; i <= v[2].first; i++) {
      s.insert({i, v[0].second});
    }
    if (v[0].second > v[1].second) {
      for (long long i = v[0].second; i >= v[1].second; i--) {
        s.insert({v[1].first, i});
      }
    } else {
      for (long long i = v[0].second; i <= v[1].second; i++) {
        s.insert({v[1].first, i});
      }
    }
    if (v[0].second > v[2].second) {
      for (long long i = v[0].second; i >= v[2].second; i--) {
        s.insert({v[2].first, i});
      }
    } else {
      for (long long i = v[0].second; i <= v[2].second; i++) {
        s.insert({v[2].first, i});
      }
    }
  }
  for (auto it : s) cout << it.first << " " << it.second << endl;
  return;
}
