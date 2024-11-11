#include <bits/stdc++.h>
using namespace std;
template <typename Tk, typename Tv>
ostream& operator<<(ostream& os, const pair<Tk, Tv>& p) {
  os << "{" << p.first << ',' << p.second << "}";
  return os;
}
const int MAX = 100005;
const int INF = 1000000000;
long long power(long long n, long long m, long long MOD) {
  if (m == 0) return 1;
  long long x = power(n, m / 2, MOD);
  if (!(m & 1))
    return (x * x) % MOD;
  else
    return (((x * x) % MOD) * n) % MOD;
}
const long long Bi = 100000007;
const long long M = 1000000009;
const long long invB = power(Bi, M - 2, M);
long long getHash(pair<char, int> x) {
  return ((x.first - 'a') * 256 + x.second) % M;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<pair<char, long long> > A, B;
  for (int i = 0; i < n; i++) {
    char s[2];
    int count;
    scanf("%d-%s", &count, s);
    char c = s[0];
    if (i > 0) {
      if (c == A.back().first) {
        A.back().second += count;
      } else {
        A.push_back(make_pair(c, count));
      }
    } else {
      A.push_back(make_pair(c, count));
    }
  }
  for (int i = 0; i < m; i++) {
    char s[2];
    int count;
    scanf("%d-%s", &count, s);
    char c = s[0];
    if (i > 0) {
      if (c == B.back().first) {
        B.back().second += count;
      } else {
        B.push_back(make_pair(c, count));
      }
    } else {
      B.push_back(make_pair(c, count));
    }
  }
  n = A.size(), m = B.size();
  if (n < m) {
    cout << 0 << endl;
    return 0;
  }
  if (m > 2) {
    long long h = 0;
    for (int i = m - 2; i >= 1; i--) {
      h *= Bi;
      h %= M;
      h += getHash(B[i]);
      h %= M;
    }
    long long g = 0;
    for (int i = m - 2; i >= 1; i--) {
      g *= Bi;
      g %= M;
      g += getHash(A[i]);
      g %= M;
    }
    long long count = 0;
    if (h == g) {
      if ((A[0].first == B[0].first) && (A[m - 1].first == B[m - 1].first)) {
        if ((A[0].second >= B[0].second) &&
            (A[m - 1].second >= B[m - 1].second)) {
          count++;
        }
      }
    }
    for (int i = m - 1; i < n - 1; i++) {
      g += (M - getHash(A[i - m + 2])) % M;
      g %= M;
      g *= invB;
      g %= M;
      g += (getHash(A[i]) * power(Bi, m - 3, M)) % M;
      g %= M;
      if (h == g) {
        if ((A[i - m + 2].first == B[0].first) &&
            (A[i + 1].first == B[m - 1].first)) {
          if ((A[i - m + 2].second >= B[0].second) &&
              (A[i + 1].second >= B[m - 1].second)) {
            count++;
          }
        }
      }
    }
    printf("%lld\n", count);
  } else if (m == 2) {
    long long count = 0;
    for (int i = 1; i < n; i++) {
      if ((A[i - 1].first == B[0].first) && (A[i].first == B[1].first)) {
        if ((A[i - 1].second >= B[0].second) && (A[i].second >= B[1].second)) {
          count++;
        }
      }
    }
    printf("%lld\n", count);
  } else {
    long long count = 0;
    for (int i = 0; i < n; i++) {
      if (A[i].first == B[0].first) {
        if (A[i].second >= B[0].second) {
          count += A[i].second - B[0].second + 1;
        }
      }
    }
    printf("%lld\n", count);
  }
}
