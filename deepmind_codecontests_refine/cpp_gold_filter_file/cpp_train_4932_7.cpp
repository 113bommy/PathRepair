#include <bits/stdc++.h>
using namespace std;
const long long int inf = 1000000000;
const long long int mod = 1000000000 + 7;
inline void IO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
inline int dcmp(long double x) { return x < -1e-12 ? -1 : (x > 1e-12); }
template <class T>
inline int CHECK(T MASK, int i) {
  return (MASK >> i) & 1;
}
template <class T>
inline T ON(T MASK, int i) {
  return MASK | (T(1) << i);
}
template <class T>
inline T OFF(T MASK, int i) {
  return MASK & (~(T(1) << i));
}
template <typename T>
inline int CNT(T MASK) {
  if (numeric_limits<T>::digits <= numeric_limits<unsigned int>::digits)
    return __builtin_popcount(MASK);
  else
    return __builtin_popcountll(MASK);
}
template <class T>
inline int RIGHT(T MASK) {
  return log2(MASK & -MASK);
}
int dx4[] = {0, 0, -1, +1};
int dy4[] = {+1, -1, 0, 0};
int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1, 0};
int dy8[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
inline void I(int& a) { scanf("%d", &a); }
inline void I(long long int& a) { scanf("%I64d", &a); }
inline void I(unsigned long long int& a) { scanf("%I64u", &a); }
inline void I(char* a) { scanf("%s", a); }
char Iarr[2000010];
inline void I(string& a) {
  scanf("%s", Iarr);
  a = Iarr;
}
template <typename T, typename... Args>
void I(T& a, Args&... args) {
  I(a);
  I(args...);
}
inline void OUT(int a) { printf("%d", a); }
inline void OUT(long long int a) { printf("%I64d", a); }
inline void OUT(const char* a) { printf("%s", a); }
inline void OUT(char* a) { printf("%s", a); }
inline void OUT(bool a) { printf("%d", a); }
inline void OUT(string a) {
  for (__typeof(a.end()) it = (a.begin()) - ((a.begin()) > (a.end()));
       it != (a.end()) - ((a.begin()) > (a.end()));
       it += 1 - 2 * ((a.begin()) > (a.end())))
    printf("%c", *it);
}
inline void OUT(unsigned long long int a) { printf("%I64u", a); }
template <typename T, typename... Args>
void OUT(T a, Args... args) {
  OUT(a);
  OUT(" ");
  OUT(args...);
}
template <typename... Args>
void O(Args... args) {
  OUT(args...);
  OUT("\n");
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& os, pair<T1, T2> p) {
  os << "{" << p.first << ", " << p.second << "}";
  return os;
}
template <typename T>
inline ostream& operator<<(ostream& os, vector<T>& a) {
  os << "[";
  for (int i = 0; i < (int)a.size(); i++) {
    if (i) os << ", ";
    os << a[i];
  }
  os << "]";
  return os;
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cout << *it << " = " << a << endl;
  err(++it, args...);
}
const int M = 100010;
vector<pair<long long int, pair<int, int> > > ans[51];
int n, p;
long double fnl = 0;
void func() {
  for (int i = 1; i <= p; i++) {
    for (pair<long long int, pair<int, int> > pp : ans[i]) {
      long double res = i * pp.first;
      int z = 1;
      int zz = 1;
      int curr = 1;
      while (1) {
        if (res > 0) {
          if (curr != n + 1)
            res /= curr++;
          else if (z != pp.second.first + 1)
            res *= z++;
          else if (zz != pp.second.second + 1)
            res *= zz++;
          else
            break;
        } else {
          if (z != pp.second.first + 1)
            res *= z++;
          else if (zz != pp.second.second + 1)
            res *= zz++;
          else if (curr != n + 1)
            res /= curr++;
          else
            break;
        }
      }
      fnl += res;
    }
  }
}
int main() {
  IO();
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> p;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  if (sum <= p) {
    cout << n << endl;
    exit(0);
  }
  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int j = 0; j < n; j++) {
      if (j != i) v.push_back(a[j]);
    }
    long long int dp[51][51][51] = {0};
    for (int j = 0; j < n - 1; j++) {
      for (int k = 0; k <= j + 1; k++) {
        for (int l = 0; l <= 50; l++) {
          if (j == 0) {
            if (k == 1 && v[j] == l)
              dp[j][k][l] = 1;
            else if (k == 0 && l == 0)
              dp[j][k][l] = 1;
          } else if (k == 0) {
            if (l == 0) dp[j][k][l] = 1;
          } else {
            dp[j][k][l] = dp[j - 1][k][l];
            if (v[j] <= l) dp[j][k][l] += dp[j - 1][k - 1][l - v[j]];
          }
        }
      }
    }
    for (int l = p - a[i] + 1; l <= p; l++) {
      for (int gb = 1; gb <= n; gb++) {
        if (l >= 0)
          if ((n - 1 - gb) > 0 && (n - 2) >= 0)
            ans[gb].push_back(
                make_pair(dp[n - 2][gb][l], make_pair(gb, n - 1 - gb)));
          else if ((n - 1 - gb) == 0 && (n - 2) >= 0)
            ans[gb].push_back(make_pair(dp[n - 2][gb][l], make_pair(gb, 1)));
        int k = (int)ans[gb].size();
        if (k != 0) {
        }
      }
    }
  }
  func();
  cout << setprecision(12) << fixed << fnl << endl;
  return 0;
}
