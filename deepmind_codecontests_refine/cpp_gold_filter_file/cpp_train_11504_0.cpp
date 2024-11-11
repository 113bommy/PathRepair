#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T BM(T p, T e, T M) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T MDINV(T a, T M) {
  return BM(a, M - 2, M);
}
template <class T>
inline T PW(T p, T e) {
  long long int ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p);
    p = (p * p);
  }
  return (T)ret;
}
template <class T>
string NTS(T Number) {
  stringstream ss;
  ss << Number;
  return ss.str();
}
template <class T>
T stringtonumber(const string &Text) {
  istringstream ss(Text);
  T result;
  return ss >> result ? result : 0;
}
int par[200005];
int segment[200005];
int find(int x) {
  if (x == par[x]) return x;
  return par[x] = find(par[x]);
}
int main() {
  int n, q, typ, x, y;
  scanf("%d%d", &n, &q);
  for (int i = 0; i <= n; i++) par[i] = segment[i] = i;
  while (q--) {
    scanf("%d%d%d", &typ, &x, &y);
    if (typ == 3) {
      x = find(x);
      y = find(y);
      if (x == y)
        puts("YES");
      else
        puts("NO");
    } else if (typ == 1) {
      x = find(x);
      y = find(y);
      if (x != y) par[x] = y;
    } else {
      typ = find(x);
      for (int i = x; i <= y;) {
        x = i;
        if (segment[x] != x) {
          par[find(segment[x])] = typ;
          i = segment[i] + 1;
        } else {
          par[find(x)] = typ;
          i++;
        }
        segment[x] = max(segment[x], y);
      }
    }
  }
  return 0;
}
