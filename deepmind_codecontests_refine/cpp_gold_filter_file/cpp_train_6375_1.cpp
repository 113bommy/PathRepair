#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& a) {
  for (T& ai : a) is >> ai;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> const& a) {
  os << "[ ";
  for (const T& ai : a) os << ai << " ";
  return os << "]";
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& a) {
  return is >> a.first >> a.second;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1, T2> const& a) {
  return os << "(" << a.first << ", " << a.second << ")";
}
class Driver {
 public:
  int n, t, s;
  void init() {
    cin >> n;
    m = 0;
    a.resize(n);
    cin >> a;
    b = a;
    update();
  }
  void insert(int x) {
    if (++m > n) throw;
    b[x] += 1;
    update();
  }
  void guess(const vector<int>& r) {
    if (a == r)
      cout << "CORRECT\n";
    else
      cout << "INCORRECT\n";
  }

 private:
  void update() {
    t = s = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] >= 3) t += (b[i] * (b[i] - 1) * (b[i] - 2)) / 6;
      if (i >= 2) s += b[i] * b[i - 1] * b[i - 2];
    }
  }

 private:
  int m;
  vector<int> a, b;
};
struct IODriver {
  int n, t, s;
  void init() { cin >> n >> t >> s; }
  void insert(int x) {
    cout << "+ " << x + 1 << endl;
    cin >> t >> s;
  }
  void guess(const vector<int>& r) {
    cout << "!";
    for (int ri : r) cout << " " << ri;
    cout << endl;
  }
};
void f() {
  IODriver d;
  d.init();
  int n = d.n;
  map<int, int> c2;
  for (int i = 2; i <= n; ++i) c2[(i * (i - 1)) / 2] = i;
  vector<int> r(n), t, s;
  t.push_back(d.t);
  s.push_back(d.s);
  for (int i = 0; i < n; ++i) {
    d.insert(i % (n - 1));
    t.push_back(d.t);
    s.push_back(d.s);
  }
  for (int i = 0; i < n - 1; ++i) {
    r[i] = c2[t[i + 1] - t[i]];
  }
  if (!r[0]) r[0] = t[n] - t[n - 1];
  int x = (s[n] - s[n - 1]) - (s[1] - s[0]) - 1;
  if (r[1] & r[2])
    ;
  else if (r[1])
    r[2] = x - r[1];
  else if (r[2])
    r[1] = x - r[2];
  else if (x == 2)
    r[1] = r[2] = 1;
  else if (x == 0)
    r[1] = r[2] = 0;
  else if (s[2] > s[1])
    r[1] = r[2]++;
  else
    r[2] = r[1]++;
  for (int i = 3; i < n - 1; ++i) {
    if (r[i]) continue;
    if (s[i] > s[i - 1] + (r[i - 2] + 1) * (r[i - 3] + 1)) ++r[i];
  }
  r[n - 1] = (s[n - 1] - s[n - 2]) / (r[n - 3] + 1) - (r[n - 4] + 1);
  d.guess(r);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  f();
  return 0;
}
