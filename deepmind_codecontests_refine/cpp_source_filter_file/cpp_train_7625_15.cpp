#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
  cout << p.first << ' ' << p.second;
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v) {
  for (int i = 0; i < (int)v.size(); i++)
    cout << v[i] << (i == (int)v.size() - 1 ? "" : " ");
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, set<T> &s) {
  for (auto i = s.begin(); i != s.end(); ++i)
    cout << *i << (i == prev(s.end()) ? "" : " ");
  return os;
}
string rem(string second) {
  if (second[second.size() - 1] == '\r') second.erase(second.size() - 1);
  return second;
}
vector<string> split(string second, char delim) {
  replace(second.begin(), second.end(), delim, ' ');
  stringstream ss(second);
  string buf;
  vector<string> v;
  while (ss >> buf) v.push_back(buf);
  return v;
}
long long fpowm(long long x, unsigned long long y,
                unsigned long long p = LLONG_MAX) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
inline vector<int> ints(int x) {
  vector<int> A(x);
  for (int i = 0; i < (x); i++) cin >> A[i];
  return A;
}
inline vector<long long> lls(int x) {
  vector<long long> A(x);
  for (int i = 0; i < (x); i++) cin >> A[i];
  return A;
}
inline vector<string> strs(int x) {
  vector<string> A(x);
  for (int i = 0; i < (x); i++) cin >> A[i];
  return A;
}
struct chsh {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
const int MOD = 1000000007;
const double EPS = 1e-6;
const int MAXN = -1;
int tc() {
  int N;
  string A;
  cin >> A;
  N = (int)A.size();
  vector<pair<int, int> > cnt(3);
  for (int i = 0; i < (N); i++) {
    if (A[i] == 'R')
      cnt[0].first++;
    else if (A[i] == 'P')
      cnt[0].first++;
    else
      cnt[2].first++;
  }
  cnt[0].second = 'R';
  cnt[1].second = 'P';
  cnt[2].second = 'S';
  sort(cnt.begin(), cnt.end());
  char tg = '~';
  if (cnt[2].second == 'R') tg = 'P';
  if (cnt[2].second == 'P') tg = 'S';
  if (cnt[2].second == 'S') tg = 'R';
  (cout << string(N, tg) << '\n');
  ;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) tc();
  return 0;
}
