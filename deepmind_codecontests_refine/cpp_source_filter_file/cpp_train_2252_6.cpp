#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
template <typename T>
T max(T A) {
  return A;
}
template <typename T, typename... args>
T max(T A, T B, args... S) {
  return max(A > B ? A : B, S...);
}
template <typename T>
T min(T A) {
  return A;
}
template <typename T, typename... args>
T min(T A, T B, args... S) {
  return min(A > B ? A : B, S...);
}
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& x : v) scanf("%d", &x);
  return in;
}
template <typename T>
ostream& operator<<(ostream& in, vector<T>& v) {
  for (auto& x : v) printf("%d ", x);
  return in;
}
long long fast(long long a, long long b, long long pr) {
  if (b == 0) return 1 % pr;
  long long ans = 1 % pr;
  while (b) {
    if (b & 1) {
      ans *= a;
      ans %= pr;
    }
    b >>= 1;
    a *= a;
    a %= pr;
  }
  return ans;
}
int readInt() {
  int n = 0;
  scanf("%d", &n);
  return n;
  int ch = getchar();
  int sign = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') sign = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    n = (n << 3) + (n << 1) + ch - '0', ch = getchar();
  n = n * sign;
  return n;
}
long long inv_(long long val) {
  return fast(val, static_cast<long long>(1e9 + 7) - 2,
              static_cast<long long>(1e9 + 7));
}
class solve {
  map<long long, long long> Squares;

 public:
  solve() {
    for (long long i = 0; i <= 1e5 + 1; i++) {
      Squares[i * i] = i;
    }
    int n;
    cin >> n;
    vector<int> v(n);
    int sq = 0;
    for (int i = 0; i < n; i++) {
      int Q = readInt();
      v[i] = Q;
      if (Squares.find(Q) != Squares.end()) {
        ++sq;
      }
    }
    if (sq * 2 == n) {
      cout << 0;
      return;
    }
    long long ans = 0;
    if (sq * 2 > n) {
      vector<int> Dist(n);
      for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
          Dist[i] = 2;
        } else if (v[i] == 1) {
          Dist[i] = 1;
        } else if (Squares.find(v[i]) != Squares.end()) {
          Dist[i] = 1;
        }
      }
      sort(Dist.begin(), Dist.end());
      for (int i = 0; i < n / 2; i++) ans += Dist[i];
    } else {
      vector<long long> Dist(n);
      for (int i = 0; i < n; i++) {
        if (Squares.find(v[i]) == Squares.end()) {
          map<long long, long long>::iterator i1 = Squares.upper_bound(v[i]);
          long long nex = i1->second;
          long long prev = i1->second - 1;
          prev* prev;
          nex *= nex;
          Dist[i] = min(abs(v[i] - prev), abs(nex - v[i]));
        }
      }
      sort(Dist.begin(), Dist.end());
      for (int i = 0; i < n / 2; i++) ans += Dist[i];
    }
    cout << ans;
  }
};
int32_t main() {
  int t = 1, i = 1;
  if (0) scanf("%d", &t);
  while (t--) {
    if (0) printf("Case #%d: ", i++);
    new solve;
  }
  return 0;
}
