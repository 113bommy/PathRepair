#include <bits/stdc++.h>
using namespace std;

//////////////////////////////   Begin Macros

#define ALL(x) (x).begin(), (x).end()
#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (int i = 1; i <= N; i++)

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &m, const T q)
{
  if (m < q)
  {
    m = q;
    return true;
  }
  else
    return false;
}
template <typename T>
bool chmin(T &m, const T q)
{
  if (m > q)
  {
    m = q;
    return true;
  }
  else
    return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first + r.first, l.second + r.second}; }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first - r.first, l.second - r.second}; }
template <typename T>
pair<T, T> operator*(const pair<T, T> &l, const T &r) { return {l.first * r, l.second * r}; }
template <typename T>
pair<T, T> operator/(const pair<T, T> &l, const T &r) { return {l.first / r, l.second / r}; }
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
  for (auto &v : vec)
    is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
  os << "[";
  for (auto v : vec)
    os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
  os << "deq[";
  for (auto v : vec)
    os << v << ",";
  os << "]";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
  os << "{";
  for (auto v : vec)
    os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
  os << "(" << pa.first << "," << pa.second << ")";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
  os << "{";
  for (auto v : mp)
    os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
  os << "{";
  for (auto v : mp)
    os << v.first << "=>" << v.second << ",";
  os << "}";
  return os;
}

template <typename T>
void reset(vector<T> &v, const T reset_to)
{
  for (auto &x : v)
    x = reset_to;
}
inline int popcount(const unsigned int x) { return __builtin_popcount(x); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

const int intinf = numeric_limits<int>::max();
#define MOD 1000000007
const pii udlr[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

//////////////////////////////   End Macros

ll L1norm(pll xy)
{
  return abs(xy.first) + abs(xy.second);
}

ll dist(pll ab, pll cd, int level)
{
  if (level == 0)
    return abs(ab.second - cd.second);

  const ll pow_three_x = pow(3, level - 1);

  const int A = ab.first / pow_three_x;
  const int C = cd.first / pow_three_x;

  if (A != C)
    return L1norm(ab - cd);

  ab.first -= A * pow_three_x;
  cd.first -= A * pow_three_x;
  level--;

  if (A != 1)
    return dist(ab, cd, level);

  // A==C==1
  const ll B = (ab.second + pow_three_x) / pow_three_x / 3;
  const ll D = (cd.second + pow_three_x) / pow_three_x / 3;
  if (B == D)
    return dist(ab, cd, level);

  const ll dx = min(abs(ab.first - (-1)) + abs(cd.first - (-1)), abs(ab.first - pow_three_x) + abs(cd.first - pow_three_x));
  const ll dy = abs(ab.second - cd.second);
  return dx + dy;
}

void solve()
{
  int Q;
  cin >> Q;
  rep(q, Q)
  {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;

    const int level_init = 30;
    ll ans = max(dist({a, b}, {c, d}, level_init), dist({b, a}, {d, c}, level_init));
    cout << ans << endl;
  }
}

int main()
{
  solve();
  return 0;
}
