#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long double PI = 2 * acos(0.0);
const vector<long long int> dx = {1, -1, 0, 0};
const vector<long long int> dy = {0, 0, 1, -1};
vector<long long int> ga(long long int n, bool oneIndexed = false) {
  vector<long long int> a;
  if (oneIndexed) a.push_back(0ll);
  for (long long int i = 0; i < n; i++) {
    long long int p;
    cin >> p;
    a.push_back(p);
  }
  return move(a);
}
vector<unsigned long long int> gau(unsigned long long int n,
                                   bool oneIndexed = false) {
  vector<unsigned long long int> a;
  if (oneIndexed) a.push_back(0llu);
  for (unsigned long long int i = 0; i < n; i++) {
    unsigned long long int p;
    cin >> p;
    a.push_back(p);
  }
  return move(a);
}
vector<string> gas(unsigned long long int n, bool oneIndexed = false) {
  vector<string> a;
  if (oneIndexed) a.push_back("");
  for (unsigned long long int i = 0; i < n; i++) {
    string p;
    cin >> p;
    a.push_back(p);
  }
  return move(a);
}
template <typename T, typename A>
void pa(vector<T, A> const &a, long long int begin = 0,
        long long int end = -1) {
  if (end == -1) end = (long long int)a.size() - 1;
  for (long long int i = begin; i <= end; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}
template <typename T, typename A>
void papair(vector<T, A> const &a, long long int begin = 0,
            long long int end = -1) {
  if (end == -1) end = (long long int)a.size() - 1;
  for (long long int i = begin; i <= end; i++) {
    cout << a[i].first << " " << a[i].second << "\n";
  }
}
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
void yesno(int f) {
  if (f)
    yes();
  else
    no();
}
void solve() {
  long long int b, w;
  cin >> b >> w;
  bool invert = false;
  if (b > w) {
    invert = true;
    long long int t = b;
    b = w;
    w = b;
  }
  if (3 * b + 1 < w) {
    no();
    return;
  };
  vector<pair<long long int, long long int> > coords;
  pair<long long int, long long int> start = {2, 3};
  for (long long int i = 0; i < b; i++) {
    coords.push_back(start);
    start.second += 2;
  }
  pair<long long int, long long int> s2 = {2, 2};
  for (long long int i = 0; i < min(b + 1, w); i++) {
    coords.push_back(s2);
    s2.second += 2;
  }
  w -= min(b + 1, w);
  s2 = {1, 3};
  for (long long int i = 0; i < min(b, w); i++) {
    coords.push_back(s2);
    s2.second += 2;
  }
  w -= min(b, w);
  s2 = {3, 3};
  for (long long int i = 0; i < min(b, w); i++) {
    coords.push_back(s2);
    s2.second += 2;
  }
  if (invert) {
    for (auto &c : coords) {
      c.first += 1;
    }
  }
  yes();
  papair(coords);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
