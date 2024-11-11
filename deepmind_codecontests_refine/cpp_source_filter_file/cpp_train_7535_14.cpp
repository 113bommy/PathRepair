#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
template <class t>
void print(t x, int end = 1) {
  cout << x << (end == 1 ? "\n" : " ");
}
template <class T>
void print(const vector<T> &v, int end = 1) {
  for (int i = 0; i < ((int)v.size()); i++) {
    print(v[i], 0);
  }
  cout << endl;
}
template <class T>
void print(const set<T> &v, int end = 1) {
  for (auto to = v.begin(); to != v.end(); to++) {
    print(*to);
  }
  cout << endl;
}
template <class T>
void print(const map<T, T> &v, int end = 1) {
  for (auto to : v) {
    print(to.first, 0);
    cout << ": ";
    print(to.second);
  }
}
template <class t>
void errprint(t x, int end = 1) {
  cerr << x << (end == 1 ? "\n" : " ");
}
void solve();
clock_t start_time;
double get_current_time() {
  return (double)(clock() - start_time) / CLOCKS_PER_SEC;
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
const int mod1 = (int)1e9 + 7, mod2 = (int)1e9 + 9;
const int p = 239;
const int limitP = 2 * (int)1e3 + 123;
string s;
int q;
vector<pair<string, ii>> req_save;
vector<ii> ans;
vector<ii> todel;
int primes1[limitP], primes2[limitP];
void init_primes() {
  primes1[0] = primes2[0] = 1;
  for (int i = 1; i < (limitP); i++) {
    primes1[i] = (ll)primes1[i - 1] * p % mod1;
    primes2[i] = (ll)primes2[i - 1] * p % mod2;
  }
}
struct hash123s {
  vector<ii> hh;
  void init(string &s) {
    hh = vector<ii>(s.size());
    hh[0].first = hh[0].second = (s[0] - 'a' + 1);
    for (int i = 1; i < (int)s.size(); i++) {
      hh[i].first =
          (hh[i - 1].first + (ll)primes1[i] * (s[i] - 'a' + 1)) % mod1;
      hh[i].second =
          (hh[i - 1].second + (ll)primes2[i] * (s[i] - 'a' + 1)) % mod2;
    }
  }
  hash123s(string &s) { init(s); }
  ii calc(int l, int r) {
    ii c = hh[r];
    if (l - 1 >= 0) {
      c.first = ((ll)c.first - hh[l - 1].first + mod1) % mod1;
      c.second = ((ll)c.second - hh[l - 1].second + mod2) % mod2;
    }
    return ii{(ll)c.first * primes1[limitP - 1 - l] % mod1,
              (ll)c.second * primes2[limitP - 1 - l] % mod2};
  }
};
int z[limitP];
void zfunc(string &s) {
  int n = (int)s.size();
  fill(z, z + s.size(), 0);
  for (int i = 1, l = 0, r = 0; i < n; i++) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i > r) l = i, r = i + z[i] - 1;
  }
}
int cnt[10][limitP];
void whats(string &t, int ind) {
  for (int i = 0; i < (q); i++) {
    string hey = t + req_save[i].first;
    zfunc(hey);
    fill(cnt[i], cnt[i] + t.size(), 0);
    for (int j = (int)t.size(); j < ((int)hey.size()); j++) {
      cnt[i][0]++;
      cnt[i][min((int)t.size(), z[j])]--;
    }
    for (int j = 1; j < (ind + 1); j++) cnt[i][j] += cnt[i][j - 1];
  }
  hash123s thash(t);
  for (int j = 0; j < (ind + 1); j++) {
    ii c = thash.calc(0, j);
    for (int i = 0; i < (q); i++) {
      if (cnt[i][j] < req_save[i].second.first ||
          req_save[i].second.second < cnt[i][j]) {
        todel.push_back(c);
        break;
      }
    }
  }
}
void solve() {
  init_primes();
  cin >> s >> q;
  req_save = vector<pair<string, ii>>(q);
  for (int i = 0; i < (q); i++) {
    cin >> req_save[i].first >> req_save[i].second.first >>
        req_save[i].second.second;
  }
  hash123s shash(s);
  for (int i = 0; i < (s.size()); i++) {
    for (int j = i; j < (s.size()); j++) {
      ii c = shash.calc(i, j);
      ans.push_back(c);
    }
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  string t = "";
  for (int i = ((int)s.size()) - 1; i >= 0; i--) {
    t = s[i] + t;
    whats(t, s.size() - i - 1);
  }
  sort(todel.begin(), todel.end());
  todel.resize(unique(todel.begin(), todel.end()) - todel.begin());
  cout << ans.size() - todel.size() << endl;
}
