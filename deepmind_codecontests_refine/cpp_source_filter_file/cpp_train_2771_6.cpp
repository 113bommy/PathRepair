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
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long lxt() {
  long long aaa;
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
int mp[2000005];
void solve() {
  int n = nxt();
  vector<int> a, b;
  for (int i = 0; i < n; i++) {
    a.push_back(nxt());
    mp[a[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    b.push_back(nxt());
    mp[b[i]] = 1;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = (a[i] ^ b[j]);
      if (mp[x] == 1) cnt++;
    }
  }
  if (cnt % 2)
    cout << "Koyomi" << '\n';
  else
    cout << "Karen" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
