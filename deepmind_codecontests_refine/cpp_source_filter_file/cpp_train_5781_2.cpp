#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i + 1 != vec.size()) os << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &st) {
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    os << *itr;
    auto titr = itr;
    if (++titr != st.end()) os << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &st) {
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    os << *itr;
    auto titr = itr;
    if (++titr != st.end()) os << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &st) {
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    os << *itr;
    auto titr = itr;
    if (++titr != st.end()) os << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &st) {
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    os << *itr;
    auto titr = itr;
    if (++titr != st.end()) os << " ";
  }
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    os << itr->first << ":" << itr->second;
    auto titr = itr;
    if (++titr != mp.end()) os << " ";
  }
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp) {
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    os << itr->first << ":" << itr->second;
    auto titr = itr;
    if (++titr != mp.end()) os << " ";
  }
  return os;
}
using ll = long long int;
using P = pair<int, int>;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
struct fast_io {
  fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
  }
} fast_io_;
int m, d;
ll dp[2][2020][2020];
void dec(string &s) {
  if (s == "1") {
    s = "0";
    return;
  }
  for (int i = ((int)(s).size()) - 1; i >= 0; i--) {
    if (s[i] > '0') {
      s[i]--;
      for (int j = i + 1; j < ((int)(s).size()); j++) {
        s[j] = '9';
      }
      break;
    }
  }
  reverse((s).begin(), (s).end());
  while (s.back() == '0') s.pop_back();
  reverse((s).begin(), (s).end());
}
ll calc(string ss) {
  vector<int> s(((int)(ss).size()));
  for (int i = (0); i < (((int)(ss).size())); ++i) s[i] = int(ss[i] - '0');
  for (int i = (0); i < (((int)(s).size()) + 1); ++i) {
    for (int j = (0); j < (m); ++j) {
      for (int k = (0); k < (2); ++k) {
        dp[k][i][j] = 0;
      }
    }
  }
  ll curr = s[0] % m;
  bool ok = (s[0] != d);
  for (int i = (1); i < (s[0]); ++i) {
    if (i == d) continue;
    (dp[1][1][i % m] += 1) %= mod;
  }
  for (int i = (1); i < (((int)(s).size())); ++i) {
    for (int j = (0); j < (m); ++j) {
      if (i % 2 == 0) {
        for (int k = (0); k < (10); ++k) {
          if (k == d) continue;
          (dp[1][i + 1][(10 * j + k) % m] += dp[1][i][j]) %= mod;
        }
        (dp[0][i + 1][(10 * j + d) % m] += dp[0][i][j]) %= mod;
      } else {
        for (int k = (0); k < (10); ++k) {
          if (k == d) continue;
          (dp[0][i + 1][(10 * j + k) % m] += dp[0][i][j]) %= mod;
        }
        (dp[1][i + 1][(10 * j + d) % m] += dp[1][i][j]) %= mod;
      }
    }
    if (i % 2 == 0) {
      for (int k = (1); k < (10); ++k) {
        if (k == d) continue;
        (dp[1][i + 1][k % m] += 1) %= mod;
      }
    } else {
      for (int k = (1); k < (10); ++k) {
        if (k == d) continue;
        (dp[0][i + 1][k % m] += 1) %= mod;
      }
    }
    if (ok) {
      if (i % 2 == 0) {
        for (int k = (0); k < (s[i]); ++k) {
          if (k == d) continue;
          (dp[1][i + 1][(10 * curr + k) % m] += 1) %= mod;
        }
        if (s[i] == d) ok = false;
      } else {
        if (s[i] > d) (dp[1][i + 1][(10 * curr + d) % m] += 1) %= mod;
        if (s[i] != d) ok = false;
      }
      curr = (10 * curr + s[i]) % mod;
    }
  }
  ll res = (dp[0][((int)(s).size())][0] + dp[1][((int)(s).size())][0]) % mod;
  if (ok && curr % m == 0) ++res;
  if (ss != "0" && d != 0) ++res;
  return res;
}
ll calc2(string ss) {
  ll s = stol(ss);
  ll res = 0;
  for (int i = 0; i <= s; i++) {
    if (i % m != 0) continue;
    string t = to_string(i);
    bool ok = true;
    for (int j = 1; j < ((int)(t).size()); j += 2) {
      if (t[j] != char('0' + d)) ok = false;
    }
    for (int j = 0; j < ((int)(t).size()); j += 2) {
      if (t[j] == char('0' + d)) ok = false;
    }
    if (ok) ++res;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  cin >> m >> d;
  string a, b;
  cin >> a >> b;
  dec(a);
  ll res = (calc(b) - calc(a)) % mod;
  if (res < 0) res += mod;
  cout << res << endl;
  return 0;
}
