#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline string toString(T a) {
  ostringstream os("");
  os << a;
  return os.str();
}
template <typename T>
inline long long toLong(T a) {
  long long res;
  istringstream os(a);
  os >> res;
  return res;
}
template <typename T>
inline T S(T a) {
  return a * a;
}
template <typename T>
inline T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
template <typename T>
inline unsigned long long bigmod(T a, T b, T m) {
  if (b == 0)
    return 1;
  else if (b % 2 == 0)
    return S(bigmod(a, b / 2, m)) % m;
  else
    return (a % m * bigmod(a, b - 1, m)) % m;
}
template <typename T>
inline vector<string> parse(T str) {
  vector<string> res;
  string s;
  istringstream os(str);
  while (os >> s) res.push_back(s);
  return res;
}
template <typename T>
inline unsigned long long dist(T A, T B) {
  unsigned long long res =
      (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
  return res;
}
template <typename T>
inline double cosAngle(T a, T b, T c) {
  double res = a * a + b * b - c * c;
  res = res / (2 * a * b);
  res = acos(res);
  return res;
}
template <typename T>
inline T power(T base, int po) {
  T res = 1;
  if (base == 0) return 0;
  for (int i = (0); i < (po); i++) res *= base;
  return res;
}
template <typename T>
inline bool isOn(T mask, T pos) {
  return mask & (1 << pos);
}
template <typename T>
inline int Off(T mask, T pos) {
  return mask ^ (1 << pos);
}
template <typename T>
inline int On(T mask, T pos) {
  return mask | (1 << pos);
}
string a, b;
int len;
int ar[609];
int br[609];
map<string, int> M;
int cost[609][609];
int main() {
  int ks;
  int n, k, a, b, f;
  ios_base::sync_with_stdio(0);
  cin.tie();
  string A, B;
  int idx = 1, x, y;
  cin >> n >> a >> b >> k >> f;
  for (int i = 1; i <= n; i++) {
    cin >> A >> B;
    if (M.find(A) == M.end()) {
      M[A] = idx;
      ++idx;
    }
    if (M.find(B) == M.end()) {
      M[B] = idx;
      ++idx;
    }
    ar[i] = M[A];
    br[i] = M[B];
  }
  int last = -1, total = 0, now;
  for (int i = 1; i <= n; i++) {
    if (ar[i] != last) {
      now = a;
    } else {
      now = b;
    }
    x = ar[i], y = br[i];
    if (x > y) swap(x, y);
    cost[x][y] += now;
    total += now;
    last = br[i];
  }
  priority_queue<int> Q;
  for (int i = 1; i < idx; i++) {
    for (int j = 1; j < idx; j++) {
      if (cost[i][j]) {
        Q.push(cost[i][j]);
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    if (Q.empty()) break;
    int x = Q.top();
    Q.pop();
    total = (total > total - x + f ? total - x + f : total);
  }
  cout << total << endl;
  return 0;
}
