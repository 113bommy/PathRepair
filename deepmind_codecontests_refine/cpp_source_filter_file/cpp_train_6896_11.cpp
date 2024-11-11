#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
template <typename first, typename second>
ostream& operator<<(ostream& os, const pair<first, second>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "{";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "}";
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ",";
    os << *it;
  }
  return os << "]";
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  return os << "]";
}
template <typename first, typename second>
ostream& operator<<(ostream& os, const map<first, second>& v) {
  os << "[";
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << ", ";
    os << it->first << " = " << it->second;
  }
  return os << "]";
}
void faltu() { cerr << endl; }
template <typename T>
void faltu(T a[], int n) {
  for (int i = 0; i < n; ++i) cerr << a[i] << ' ';
  cerr << endl;
}
template <typename T, typename... hello>
void faltu(T arg, const hello&... rest) {
  cerr << arg << ' ';
  faltu(rest...);
}
mt19937 rng((unsigned)chrono::system_clock::now().time_since_epoch().count());
bool check(int len, int hmm) {
  cout << "? " << len << " " << len << '\n';
  for (int i = 1; i <= len; ++i) cout << i << " ";
  cout << '\n';
  for (int i = hmm + 1; i <= hmm + len; ++i) cout << i << " ";
  cout << endl;
  string s;
  cin >> s;
  if (s == "WASTED" || s == "SECOND") exit(0);
  if (s == "EQUAL") return 0;
  if (s == "FIRST") return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    bool ok = 0;
    for (int i = 0; i < 30; ++i) {
      cout << "? 1 1" << '\n';
      cout << '1' << '\n';
      int temp = (rng() % n) + 1;
      if (temp == 1) ++temp;
      cout << temp << endl;
      string s;
      cin >> s;
      if (s == "FIRST" || s == "EQUAL") continue;
      if (s == "WASTED") exit(0);
      if (s == "SECOND") {
        cout << "! 1" << endl;
        ok = 1;
        break;
      }
    }
    if (ok) continue;
    int sz;
    int hmm;
    for (int i = 1; i * 2 <= n; i *= 2) {
      cout << "? " << i << " " << i << '\n';
      for (int j = 1; j <= i; ++j) cout << j << " ";
      cout << '\n';
      for (int j = i + 1; j <= i + i; ++j) cout << j << " ";
      cout << endl;
      string s;
      cin >> s;
      if (s == "WASTED" || s == "SECOND") exit(0);
      if (s == "EQUAL") {
        hmm = 1;
        sz = n - i;
        continue;
      }
      if (s == "FIRST") {
        hmm = i;
        sz = i;
        break;
      }
    }
    int lo = 1, hi = sz, mid;
    while (lo <= hi) {
      mid = (lo + hi) / 2;
      if (check(mid, hmm))
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    cout << "! " << hmm + lo << endl;
  }
}
