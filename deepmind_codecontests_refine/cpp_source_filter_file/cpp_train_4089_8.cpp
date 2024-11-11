#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &str, vector<T> &a) {
  for (auto &i : a) {
    str << i << " ";
  }
  return str;
}
template <class T>
istream &operator>>(istream &str, vector<T> &a) {
  for (auto &i : a) {
    str >> i;
  }
  return str;
}
template <class T>
ostream &operator<<(ostream &str, pair<T, T> &a) {
  str << a.first << " " << a.second;
  return str;
}
template <class T>
istream &operator>>(istream &str, pair<T, T> &a) {
  str >> a.first >> a.second;
  return str;
}
void solve();
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(6);
  solve();
  return 0;
}
const long long MOD = 998244353, MAXN = 5e5 + 10, INF = 1e18 + 10, BASE = 37;
void query() {
  long long n, first, second;
  cin >> n >> first >> second;
  vector<long long> a(n);
  cin >> a;
  vector<long long> b(n);
  map<long long, vector<long long>> id;
  for (long long i = 0; i < n; ++i) {
    id[a[i]].push_back(i);
  }
  set<pair<long long, long long>> se;
  for (auto it : id) {
    se.insert({(long long)((it.second).size()), it.first});
  }
  vector<long long> f;
  for (long long i = 0; i < first; ++i) {
    f.push_back(id[(--se.end())->second].back());
    id[(--se.end())->second].pop_back();
    auto it = *(--se.end());
    se.erase(--se.end());
    it.first--;
    se.insert(it);
  }
  for (auto it : f) {
    b[it] = a[it];
  }
  long long NUM = 0;
  map<long long, long long> ch;
  for (auto it : a) {
    ch[it] = 1;
  }
  for (long long i = 1; i <= n + 1; ++i) {
    if (ch[i] == 0) {
      NUM = i;
      break;
    }
  }
  vector<long long> cur;
  for (auto it : se) {
    for (auto i : id[it.second]) {
      cur.push_back(i);
    }
  }
  if ((second - first) <= n - first - (--se.end())->first) {
    long long A = (--se.end())->first;
    cout << "YES" << '\n';
    for (long long i = 0; i < (second - first); ++i) {
      b[cur[i] + A] = a[cur[i]];
    }
    for (long long i = 0; i < n; ++i) {
      if (b[i] == 0) {
        b[i] = NUM;
      }
    }
    cout << b << '\n';
  } else {
    long long A = (--se.end())->first;
    if (second - first - (n - first - A) <= (n - first - A)) {
      cout << "YES" << '\n';
      for (long long i = 0; i < (n - first - A); ++i) {
        b[cur[i] + A] = a[cur[i]];
      }
      for (long long i = 0; i < (second - first) - (n - first - A); ++i) {
        b[cur[i]] = a[cur[i + (n - first - A)]];
      }
      for (long long i = 0; i < n; ++i) {
        if (b[i] == 0) {
          b[i] = NUM;
        }
      }
      cout << b << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}
void solve() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    query();
  }
}
