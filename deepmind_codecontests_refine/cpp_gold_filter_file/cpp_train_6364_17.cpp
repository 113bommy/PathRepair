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
int minn(int a, int b, int c) {
  int ret = a;
  ret = min(ret, b);
  ret = min(ret, c);
  return ret;
}
int main() {
  int n;
  I(n);
  int a[n];
  for (int i = 0; i < n; i++) {
    I(a[i]);
  }
  int ans = inf;
  int t = -1;
  for (int i = 1; i <= 200; i++) {
    int temp = 0;
    for (int j = 0; j < n; j++) {
      temp += minn(abs(a[j] - i), abs(a[j] - (i + 1)), abs(a[j] - (i - 1)));
    }
    if (temp < ans) {
      ans = temp;
      t = i;
    }
  }
  O(t, ans);
  return 0;
}
