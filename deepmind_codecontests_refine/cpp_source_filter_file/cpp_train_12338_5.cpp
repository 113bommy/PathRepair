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
ll dp[2020][2020];
int pre[2020][2020], typ[2020][2020];
int main(int argc, char const *argv[]) {
  int n, s;
  cin >> n >> s;
  s--;
  vector<ll> a(n);
  cin >> a;
  map<ll, vector<int>> mp;
  for (int i = (0); i < (n); ++i) mp[a[i]].emplace_back(i);
  for (int i = (0); i < (n + 1); ++i) dp[0][i] = linf;
  dp[0][s] = 0;
  int cnt = 1;
  for (auto itr = (mp).begin(); itr != (mp).end(); ++itr) {
    for (int j = (0); j < (n + 1); ++j) dp[cnt][j] = linf;
    auto &v = itr->second;
    auto ptr = itr;
    if (ptr != mp.begin()) ptr--;
    vector<int> pr = (itr == mp.begin() ? vector<int>{s} : ptr->second);
    for (auto j : pr) {
      for (auto k : v) {
        if (j < k) {
          ll tmp1 = dp[cnt - 1][j] + j + 1 + (n - 1 - k);
          int li = upper_bound((v).begin(), (v).end(), j) - v.begin();
          if (li < ((int)(v).size()) && v[li] < k) tmp1 += 2LL * (k - v[li]);
          if (dp[cnt][k] > tmp1) {
            dp[cnt][k] = tmp1;
            pre[cnt][k] = j;
            typ[cnt][k] = 1;
          }
          ll tmp2 = dp[cnt - 1][j];
          int kp = lower_bound((v).begin(), (v).end(), k) - v.begin();
          kp--;
          if (kp >= 0 && v[kp] > j) tmp2 += 2LL * (v[kp] - j);
          tmp2 += j + 1 + (n - 1 - k);
          if (dp[cnt][k] > tmp2) {
            dp[cnt][k] = tmp2;
            pre[cnt][k] = j;
            typ[cnt][k] = 2;
          }
          ll tmp3 = dp[cnt - 1][j];
          if (v[0] < j) tmp3 += 2LL * (j - v[0]);
          tmp3 += (k - j);
          if (v.back() > k) tmp3 += 2LL * (v.back() - k);
          if (dp[cnt][k] > tmp3) {
            dp[cnt][k] = tmp3;
            pre[cnt][k] = j;
            typ[cnt][k] = 3;
          }
        } else {
          ll tmp1 = dp[cnt - 1][j] + (n - 1 - j) + 1 + k;
          int li = lower_bound((v).begin(), (v).end(), j) - v.begin();
          li--;
          if (li < ((int)(v).size()) && v[li] > k) tmp1 += 2LL * (v[li] - k);
          if (dp[cnt][k] > tmp1) {
            dp[cnt][k] = tmp1;
            pre[cnt][k] = j;
            typ[cnt][k] = 1;
          }
          ll tmp2 = dp[cnt - 1][j];
          int kb = upper_bound((v).begin(), (v).end(), k) - v.begin();
          if (kb < ((int)(v).size()) && v[kb] < j) tmp2 += 2LL * (j - v[kb]);
          tmp2 += (n - 1 - j) + 1 + k;
          if (dp[cnt][k] > tmp2) {
            dp[cnt][k] = tmp2;
            pre[cnt][k] = j;
            typ[cnt][k] = 2;
          }
          ll tmp3 = dp[cnt - 1][j];
          if (v.back() > j) tmp3 += 2LL * (v.back() - j);
          tmp3 += (j - k);
          if (v[0] < k) tmp3 += 2LL * (k - v[0]);
          if (dp[cnt][k] > tmp3) {
            dp[cnt][k] = tmp3;
            pre[cnt][k] = j;
            typ[cnt][k] = 3;
          }
        }
      }
    }
    cnt++;
  }
  ll res = linf;
  int k = -1;
  for (auto e : mp.rbegin()->second) {
    if (res > dp[cnt - 1][e]) {
      res = dp[cnt - 1][e];
      k = e;
    }
  }
  cout << res << endl;
  cnt--;
  vector<int> od;
  od.reserve(n);
  while (((int)(od).size()) < n) {
    int p = pre[cnt][k];
    vector<int> &v = mp[a[k]];
    if (cnt == 0) {
      od.emplace_back(s);
      break;
    }
    if (p < k) {
      if (typ[cnt][k] == 1) {
        int ri = upper_bound((v).begin(), (v).end(), p) - v.begin();
        od.emplace_back(k);
        for (; ri < ((int)(v).size()); ri++)
          if (v[ri] != k) od.emplace_back(v[ri]);
        for (int j = 0; v[j] < p; j++) od.emplace_back(v[j]);
      } else if (typ[cnt][k] == 2) {
        int ki = lower_bound((v).begin(), (v).end(), k) - v.begin();
        for (; ki < ((int)(v).size()); ki++) od.emplace_back(v[ki]);
        for (int j = 0; v[j] < k; j++) {
          if (v[j] != p) od.emplace_back(v[j]);
        }
      } else {
        od.emplace_back(k);
        for (int j = ((int)(v).size()) - 1; j >= 0; j--) {
          if (v[j] != k && v[j] != p) od.emplace_back(v[j]);
        }
      }
    } else {
      if (typ[cnt][k] == 1) {
        od.emplace_back(k);
        int ki = lower_bound((v).begin(), (v).end(), p) - v.begin();
        ki--;
        for (; ki >= 0; ki--)
          if (v[ki] != k) od.emplace_back(v[ki]);
        for (int j = ((int)(v).size()) - 1; j >= 0 && v[j] > p; j--)
          od.emplace_back(v[j]);
      } else if (typ[cnt][k] == 2) {
        int ki = lower_bound((v).begin(), (v).end(), k) - v.begin();
        for (; ki >= 0; ki--) od.emplace_back(v[ki]);
        for (int j = ((int)(v).size()) - 1; j >= 0 && v[j] > k; j--) {
          if (v[j] != p) od.emplace_back(v[j]);
        }
      } else {
        od.emplace_back(k);
        for (int j = 0; j < ((int)(v).size()) - 1; j++) {
          if (v[j] != k && v[j] != p) od.emplace_back(v[j]);
        }
      }
    }
    cnt--;
    k = p;
  }
  reverse((od).begin(), (od).end());
  cerr << od << endl;
  for (int i = (0); i < (n); ++i) {
    int prev = (i == 0 ? s : od[i - 1]);
    if (abs(od[i] - prev) < n - abs(prev - od[i])) {
      if (prev > od[i])
        cout << "-";
      else
        cout << "+";
      cout << abs(od[i] - prev) << "\n";
    } else {
      if (prev < od[i])
        cout << "-";
      else
        cout << "+";
      cout << n - abs(prev - od[i]) << "\n";
    }
  }
  cout << flush;
  return 0;
}
