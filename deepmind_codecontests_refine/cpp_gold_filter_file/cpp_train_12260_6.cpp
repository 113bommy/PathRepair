#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << '=' << h << endl;
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << '=' << h << ',';
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, set<T> V) {
  os << "[";
  for (auto vv : V) os << vv << ",";
  return os << "]";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
long long losuj(long long n, long long m) {
  vector<long long> p(n);
  vector<long long> vis(n);
  for (long long i = 0; i < (n); i++) p[i] = i;
  for (long long i = 0; i < (m); i++) {
    long long a = rand() % n;
    long long b = rand() % n;
    if (a == b) i--;
    swap(p[a], p[b]);
  }
  long long res = 0;
  for (long long i = 0; i < (n); i++) {
    if (vis[i] == 0) {
      res++;
      long long ak = i;
      while (vis[ak] == 0) {
        vis[ak] = 1;
        ak = p[ak];
      }
    }
  }
  return res;
}
void spr(long long n) {
  (n);
  for (long long i = 0; i < (10); i++) {
    if (0) cout << losuj(n, 3 * n) << " ";
  }
  if (0) cout << "\n";
  for (long long i = 0; i < (10); i++) {
    if (0) cout << losuj(n, 7 * n + 1) << " ";
  }
  if (0) cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  if (0) cout << fixed << setprecision(6);
  long long n;
  cin >> n;
  vector<long long> p(n);
  vector<long long> vis(n);
  for (long long i = 0; i < (n); i++) {
    cin >> p[i];
    p[i]--;
  }
  long long res = 1;
  for (long long i = 0; i < (n); i++) {
    if (vis[i] == 0) {
      res = !res;
      long long ak = i;
      while (vis[ak] == 0) {
        vis[ak] = 1;
        ak = p[ak];
      }
    }
  }
  if (res) {
    cout << "Petr\n";
  } else {
    cout << "Um_nik\n";
  }
}
