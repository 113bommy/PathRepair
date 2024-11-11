#include <bits/stdc++.h>
using namespace std;
const int Sz = 4e5 + 5;
const int Mod = 1e9 + 7;
const long long LL_INF = 1e16;
const int INF = 1e9;
const double PI = 2 * acos(0.0);
vector<vector<long long> > operator*(const vector<vector<long long> > &a,
                                     const vector<vector<long long> > &b) {
  vector<vector<long long> > res(a.size(), b[0]);
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)b[0].size(); j++) {
      for (int k = 0; k < (int)b.size(); k++) {
        (res[i][j] += a[i][k] * b[k][j]);
      }
    }
  }
  return res;
}
void show(ostream &out, const vector<vector<long long> > &x) {
  for (int i = 0; i < (int)x.size(); i++) {
    for (int j = 0; j < (int)x[i].size(); j++) {
      out << x[i][j] << " ";
    }
    out << endl;
  }
}
array<long long, 2> operator+(const array<long long, 2> &a,
                              const array<long long, 2> &b) {
  return {a[0] + b[0], a[1] + b[1]};
}
array<long long, 2> operator-(const array<long long, 2> &a,
                              const array<long long, 2> &b) {
  return {a[0] - b[0], a[1] - b[1]};
}
array<long long, 2> operator*(const array<long long, 2> &a,
                              const array<long long, 2> &b) {
  return {a[0] * b[0], a[1] * b[1]};
}
array<long long, 2> operator%(const array<long long, 2> &a,
                              const array<long long, 2> &b) {
  return {a[0] % b[0], a[1] % b[1]};
}
long long operator^(const array<long long, 2> &a,
                    const array<long long, 2> &b) {
  return a[0] * b[0] + a[1] * b[1];
}
struct Hash : string {
 private:
  const array<long long, 2> Mod = {(long long)1e9 + 7, (long long)1e9 + 9};
  const array<long long, 2> Base = {27, 31};
  vector<array<long long, 2> > MEMHASH, POW;
  int digit(char x) { return x - 'a' + 1; }

 public:
  void Hashing() {
    array<long long, 2> key = {digit((*this)[0]), digit((*this)[0])};
    MEMHASH.push_back(key);
    POW.push_back({1, 1});
    for (int i = 1; i < (int)(*this).size(); i++) {
      key = {digit((*this)[i]), digit((*this)[i])};
      MEMHASH.push_back((MEMHASH.back() * Base + key) % Mod);
      POW.push_back(POW.back() * Base % Mod);
    }
  }
  array<long long, 2> Get(int l, int r) {
    if (l == 0)
      return MEMHASH[r];
    else
      return MEMHASH[r] - MEMHASH[l - 1];
  }
};
template <typename T>
void FastScan(T &number) {
  bool negative = false;
  int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
template <typename T>
void FastPrint(T number) {
  if (number < 0) {
    putchar('-');
    number *= -1;
  }
  if (number > 9) FastPrint(number / 10);
  putchar(48 + number % 10);
  return;
}
template <typename T>
T Power(T a, long long n) {
  if (n == 1) return a;
  if (n & 1) return a * Power(a * a, n >> 1);
  return Power(a * a, n >> 1);
}
mt19937_64 rng(time(0));
long long Rand(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng);
}
long double RRand(long double l, long double r) {
  return uniform_real_distribution<long double>(l, r)(rng);
}
long long Access(long long bin, long long bit) { return (bin >> bit) & 1; }
long long TurnOn(long long bin, long long bit) { return bin | (1ll << bit); }
long long TurnOff(long long bin, long long bit) {
  return TurnOn(bin, bit) ^ (1ll << bit);
}
long long Switch(long long bin, long long bit) { return bin ^ (1ll << bit); }
long long l[Sz];
long long r[Sz];
int n;
void read() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
}
void zip() {
  vector<int> value;
  for (int i = 1; i <= n; i++) {
    value.push_back(l[i]);
    value.push_back(r[i]);
  }
  sort(value.begin(), value.end());
  value.erase(unique(value.begin(), value.end()), value.end());
  for (int i = 1; i <= n; i++) {
    l[i] = upper_bound(value.begin(), value.end(), l[i]) - value.begin();
    r[i] = upper_bound(value.begin(), value.end(), r[i]) - value.begin();
  }
}
bool Union(array<long long, 2> x, array<long long, 2> y) {
  return max(x[0], y[0]) <= min(x[1], y[1]);
}
void solve() {
  set<array<long long, 2> > s;
  for (int i = 1; i <= n; i++) {
    auto p = s.lower_bound({l[i], -1});
    if (p != s.begin()) p = prev(p);
    int cnt = 0;
    while (p != s.end()) {
      if (cnt == 3) break;
      if (Union({l[i], r[i]}, *p)) {
        auto temp = p;
        p = next(p);
        l[i] = min(l[i], (*temp)[0]);
        r[i] = max(r[i], (*temp)[1]);
        s.erase(temp);
      } else {
        cnt++;
        p = next(p);
      }
    }
    s.insert({l[i], r[i]});
    cout << s.size() << " \n"[i == n];
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  read();
  zip();
  solve();
  return 0;
}
