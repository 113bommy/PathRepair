#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000500;
inline int g() {
  int x;
  cin >> x;
  return x;
}
inline long long gl() {
  long long x;
  cin >> x;
  return x;
}
inline char gc() {
  char x;
  cin >> x;
  return x;
}
inline string gs() {
  string s;
  cin >> s;
  return s;
}
template <typename T>
inline vector<T> gv(int len) {
  vector<T> a(len);
  for (auto& it : a) cin >> it;
  return a;
}
inline vector<int> gv(int len) {
  vector<int> a(len);
  for (auto& it : a) cin >> it;
  return a;
}
inline vector<pair<int, int>> gv_andPairCnt(int len) {
  vector<pair<int, int>> a(len);
  int i = 1;
  for (auto& it : a) {
    it.second = i;
    i++;
    cin >> it.first;
  }
  return a;
}
double power_log(double power, double val) { return log(val) / log(power); }
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto it : v) os << it << ", ";
  os << "\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const deque<T>& v) {
  os << "deque:{";
  for (auto it : v) os << it << " ";
  os << "}\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "set:{";
  for (auto it : v) os << it << " ";
  os << "}\n";
  return os;
}
template <typename T, typename H>
inline vector<pair<T, H>> gv_andBiPair(int len) {
  vector<pair<T, H>> a(len);
  for (auto& it : a) {
    cin >> it.first >> it.second;
  }
  return a;
}
template <typename T>
inline set<T> vector_to_set(const vector<T>& vec) {
  set<T> s;
  for (auto& it : vec) s.insert(it);
  return s;
}
const long long md = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = g();
  for (int t1 = 0; t1 < (t); ++t1) {
    int n = g(), d = g();
    vector<int> cnt(n + 3);
    vector<int> p(n + 3);
    vector<int> bad(n + 3);
    vector<int> depth(n + 3);
    depth[1] = 0;
    for (int i = 2; i <= n; i++) {
      p[i] = i - 1;
      cnt[i - 1]++;
      depth[i] = i - 1;
    }
    int k = accumulate(depth.begin(), depth.end(), 0LL);
    int mx_b = 0, pw = 1, c = n;
    for (int de = 0;; de++) {
      mx_b += min(pw, c) * de;
      c -= min(pw, c);
      pw *= 2;
      if (c <= 0) {
        break;
      }
    }
    if (d < mx_b) {
      cout << "NO\n";
      continue;
    }
    while (k > d) {
      int v = -1;
      for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0 && !bad[i]) {
          if (v == -1) {
            v = i;
          } else {
            if (depth[v] > depth[i]) {
              v = i;
            }
          }
        }
      }
      if (v == -1) {
        break;
      }
      bool fl = false;
      for (int i = 1; i <= n; i++) {
        if (i != v && cnt[i] < 2 && depth[i] + 2 == depth[v]) {
          fl = true;
          int pp = p[v];
          cnt[pp]--;
          p[v] = i;
          cnt[i]++;
          depth[v] = depth[i] + 1;
          break;
        }
      }
      if (!fl) {
        bad[v] = true;
        continue;
      }
      k--;
    }
    if (k == d) {
      cout << "YES\n";
      for (int i = 2; i <= n; i++) {
        cout << p[i] << " ";
      }
      cout << "\n";
    } else {
      cout << "NO\n";
    }
  }
}
