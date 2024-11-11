#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <class T>
inline bool setmin(T &a, T b) {
  if (a > b) return a = b, 1;
  return 0;
}
template <class T>
inline bool setmax(T &a, T b) {
  if (a < b) return a = b, 1;
  return 0;
}
template <class T>
inline T fast(T a, T b, T mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
template <class T>
istream &operator>>(istream &os, vector<T> &container) {
  for (auto &u : container) os >> u;
  return os;
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &container) {
  for (auto &u : container) os << u << " ";
  return os;
}
template <class T>
inline T gcd(T a, T b) {
  while (b) swap(a %= b, b);
  return abs(a);
}
const long long INF = 1e9 + 7;
const long long mod = 998244353;
const long long BIG_INF = 1e18 + 7;
const long long N = 1e6 + 7;
const long long T = 1 << 20;
const long double inf = 1e18;
long long n, m, q, k;
int S = (1 << 8);
int tab[N];
int poz[N];
int cnt;
vector<pair<int, int> > ans;
struct Kubek {
  vector<pair<int, int> > wartosci;
  int mini = INF, maxi = 0;
  vector<vector<int> > dp;
  void add_val(pair<int, int> val) { wartosci.push_back(val); }
  int dp_poz(int val) {
    for (int i = 0; i < (int)(wartosci).size(); i++)
      if (val == wartosci[i].second) return i;
    assert(false);
  }
  int id_przedzialu(int pocz, int kon) {
    pocz = dp_poz(pocz);
    kon = dp_poz(kon);
    assert(pocz <= kon);
    if (pocz == kon) return wartosci[pocz].first;
    return dp[pocz][kon];
  }
  void init() {
    sort((wartosci).begin(), (wartosci).end());
    assert((int)(wartosci).size());
    if ((int)(wartosci).size() == 1) {
      return;
    }
    for (auto &u : wartosci) {
      mini = min(mini, u.second);
      maxi = max(maxi, u.second);
    }
    Kubek mniejsze, wieksze;
    int mid = (mini + maxi) / 2;
    for (auto &u : wartosci) (u.second <= mid ? mniejsze : wieksze).add_val(u);
    mniejsze.init();
    wieksze.init();
    dp = vector<vector<int> >((int)(wartosci).size(),
                              vector<int>((int)(wartosci).size(), -1));
    for (int i = 0; i < (int)(wartosci).size(); i++) {
      for (int j = i + 1; j < (int)(wartosci).size(); j++) {
        int pierwszy_mniejszy = -1;
        int ostatni_mniejszy = -1;
        int pierwszy_wiekszy = -1;
        int ostatni_wiekszy = -1;
        for (int l = i; l <= j; l++) {
          if (wartosci[l].second <= mid) {
            if (pierwszy_mniejszy == -1) pierwszy_mniejszy = wartosci[l].second;
            ostatni_mniejszy = wartosci[l].second;
          } else {
            if (pierwszy_wiekszy == -1) pierwszy_wiekszy = wartosci[l].second;
            ostatni_wiekszy = wartosci[l].second;
          }
        }
        if (pierwszy_wiekszy == -1)
          dp[i][j] =
              mniejsze.id_przedzialu(pierwszy_mniejszy, ostatni_mniejszy);
        else if (pierwszy_mniejszy == -1)
          dp[i][j] = wieksze.id_przedzialu(pierwszy_wiekszy, ostatni_wiekszy);
        else {
          ans.push_back(
              {mniejsze.id_przedzialu(pierwszy_mniejszy, ostatni_mniejszy),
               wieksze.id_przedzialu(pierwszy_wiekszy, ostatni_wiekszy)});
          dp[i][j] = cnt++;
        }
      }
    }
  }
};
Kubek kubki[N];
void solve() {
  cin >> n >> k;
  cnt = n;
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
    tab[i]--;
    poz[tab[i]] = i;
  }
  for (int i = 0; i < (n + (S - 1)) / S; i++) {
    int mini = i * S;
    for (int j = 0; j < S; j++)
      if (j + mini < n) kubki[i].add_val({poz[mini + j], mini + j});
    kubki[i].init();
  }
  vector<int> ans2;
  while (k--) {
    int pocz;
    int kon;
    cin >> pocz >> kon;
    pocz--, kon--;
    int przedzial = -1;
    for (int i = 0; i < (n + (S - 1)) / S; i++) {
      int pierwszy = -1;
      int ostatni = -1;
      for (auto &u : kubki[i].wartosci)
        if (u.first <= kon and u.first >= pocz) {
          if (pierwszy == -1) pierwszy = u.second;
          ostatni = u.second;
        }
      if (pierwszy == -1) continue;
      if (przedzial == -1)
        przedzial = kubki[i].id_przedzialu(pierwszy, ostatni);
      else {
        ans.push_back({przedzial, kubki[i].id_przedzialu(pierwszy, ostatni)});
        przedzial = cnt++;
      }
    }
    ans2.push_back(przedzial + 1);
  }
  cout << cnt << '\n';
  for (auto &u : ans) cout << u.first + 1 << ' ' << u.second + 1 << '\n';
  cout << ans2 << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  q = 1;
  while (q--) solve();
}
