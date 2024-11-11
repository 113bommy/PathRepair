#include <bits/stdc++.h>
#pragma comment(linker, "/stack:640000000")
using namespace std;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template <class T>
inline T _abs(T n) {
  return ((n) < 0 ? -(n) : (n));
}
template <class T>
inline T _max(T a, T b) {
  return (!((a) < (b)) ? (a) : (b));
}
template <class T>
inline T _min(T a, T b) {
  return (((a) < (b)) ? (a) : (b));
}
template <class T>
inline T _swap(T &a, T &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
struct debugger {
  template <typename T>
  debugger &operator,(const T &v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int strToint(string x) {
  stringstream ss(x);
  int i;
  ss >> i;
  return i;
}
struct movie {
  int ind, audio, sub;
  movie() {}
  movie(int a, int b, int c) {
    ind = a;
    audio = b;
    sub = c;
  }
  bool operator<(const movie &p) const {
    if (audio == p.audio) return sub > p.sub;
    return audio > p.audio;
  }
} ara[200005];
map<int, int> mp;
int main() {
  int n;
  while (scanf("%d", &n) == 1) {
    mp.clear();
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      mp[x]++;
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int x;
      scanf("%d", &x);
      ara[i].ind = i + 1;
      int tmp;
      if (!mp.count(x))
        tmp = 0;
      else
        tmp = mp[x];
      ara[i].audio = tmp;
    }
    for (int i = 0; i < m; i++) {
      int x;
      scanf("%d", &x);
      int tmp;
      if (!mp.count(x))
        tmp = 0;
      else
        tmp = mp[x];
      ara[i].sub = tmp;
    }
    sort(ara, ara + m);
    printf("%d\n", ara[0].ind);
  }
  return 0;
}
