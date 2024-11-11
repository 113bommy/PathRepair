#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& it : v) is >> it;
  return is;
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> second) {
  os << "{ ";
  for (auto s : second) os << s << " ";
  return os << "}";
}
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " |";
  __f(comma + 1, args...);
}
void solve() {
  long long n, k, m;
  cin >> n >> k >> m;
  long long tot = n * m;
  vector<long long> arr(n);
  cin >> arr;
  vector<pair<long long, long long> > stk;
  for (long long i : arr) {
    if (stk.empty() or stk.back().first != i) {
      stk.push_back({i, 1});
    } else {
      stk.back().second++;
      if (stk.back().second == k) {
        stk.pop_back();
        tot -= k * m;
      }
    }
  }
  if (stk.size() == 0) {
    cout << 0 << '\n';
    return;
  }
  long long i = 0, j = stk.size() - 1;
  while (j > i) {
    if (stk[i].first == stk[j].first and stk[i].second + stk[j].second >= k) {
      tot -= k * (m - 1);
      if (stk[i].second + stk[j].second == k)
        i++, j--;
      else
        break;
    } else {
      break;
    }
  }
  if (j > i) {
    cout << tot << '\n';
  } else if ((m * stk[i].second) % k == 0) {
    cout << 0 << '\n';
  } else {
    cout << tot - m * stk[i].second / k * k << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
