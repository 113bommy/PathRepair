#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long int lxt() {
  long long int aaa;
  scanf("%lld", &aaa);
  return aaa;
}
inline double dxt() {
  double aaa;
  scanf("%lf", &aaa);
  return aaa;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
int ar[1000010];
long long int getRandom(long long int l, long long int r) {
  long long int tmp = r - l + 1;
  int x = rand() % tmp;
  return l + x;
}
bool isContain(long long int l, long long int r) {
  cout << l << " " << r << endl;
  string s;
  cin >> s;
  if (s == "Yes") return 1;
  if (s == "No") return 0;
  assert(0);
}
int main() {
  srand(time(0));
  long long int n;
  int k;
  cin >> n >> k;
  long long int l = 1;
  long long int r = n;
  while (1) {
    while (r - l > 4 * k) {
      long long int mid = (l + r) / 2;
      if (isContain(l, mid)) {
        l = max(1LL, l - k);
        r = min(n, mid + k);
      } else {
        l = max(1LL, mid - k);
        r = min(n, r + k);
      }
    }
    long long int tmp = getRandom(l, r);
    if (isContain(tmp, tmp)) {
      break;
    } else {
      l -= k;
      l = max(l, 1LL);
      r += k;
      r = min(r, n);
    }
  }
  return 0;
}
