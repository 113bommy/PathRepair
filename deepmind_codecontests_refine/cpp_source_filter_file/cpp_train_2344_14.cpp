#include <bits/stdc++.h>
using namespace std;
long long M;
template <int DEG>
void cp(long long a[DEG][DEG], long long b[DEG][DEG]) {
  memcpy(b, a, sizeof(long long) * DEG * DEG);
}
template <int DEG>
void mul(long long a[DEG][DEG], long long b[DEG][DEG], long long c[DEG][DEG]) {
  long long t[DEG][DEG] = {};
  for (int i = 0; i < DEG; i++) {
    for (int k = 0; k < DEG; k++) {
      for (int j = 0; j < DEG; j++) {
        t[i][j] += (a[i][k] * b[k][j]);
        t[i][j] %= M;
      }
    }
  }
  cp(t, c);
}
template <int DEG>
void pow(long long a[DEG][DEG], long long e, long long r[DEG][DEG]) {
  long long p[DEG][DEG] = {};
  cp(a, p);
  for (int i = 0; i < DEG; i++) {
    for (int j = 0; j < DEG; j++) {
      r[i][j] = 0;
    }
    r[i][i] = 1;
  }
  while (e) {
    if (e % 2) {
      mul(r, p, r);
    }
    mul(p, p, p);
    e /= 2;
  }
}
template <int DEG>
void add(long long a[DEG][DEG], long long b[DEG][DEG], long long c[DEG][DEG]) {
  for (int i = 0; i < DEG; i++) {
    for (int j = 0; j < DEG; j++) {
      c[i][j] = (a[i][j] + b[i][j]) % M;
    }
  }
}
long long powmod(long long p, long long n, long long mod) {
  long long q = p % mod;
  long long pow = 1;
  while (n) {
    if (n & 1) {
      pow *= q;
      pow %= mod;
    }
    q = q * q;
    q %= mod;
    n /= 2;
  }
  return pow;
}
const int L = 1e6;
long long vs[L];
int f(vector<int> cur, int x, int y) {
  vector<int> nex;
  for (int i = 0; i < x; i++) {
    nex.clear();
    nex.push_back(cur[0]);
    for (int i = 1; i < cur.size(); i++) {
      nex.push_back(cur[i - 1] + cur[i]);
      nex.push_back(cur[i]);
    }
    cur.swap(nex);
  }
  sort(cur.begin(), cur.end());
  cerr << cur.front() << ", " << cur.back() << endl;
  for (int i = 0; i < y; i++) {
    nex.clear();
    nex.push_back(cur[0]);
    for (int i = 1; i < cur.size(); i++) {
      nex.push_back(cur[i - 1] + cur[i]);
      nex.push_back(cur[i]);
    }
    cur.swap(nex);
  }
  int s = 0;
  for (auto c : cur) {
    s += c;
  }
  return s;
}
int main() {
  long long n, x, y;
  scanf("%lld%lld%lld%lld", &n, &x, &y, &M);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld", vs + i);
    vs[i] %= M;
    sum += vs[i];
    sum %= M;
  }
  if (n == 1) {
    printf("%lld\n", vs[0]);
    return 0;
  }
  sum += M - vs[0];
  sum %= M;
  sum += M - vs[n - 1];
  sum %= M;
  sum = sum * powmod(3, x, M) % M;
  long long m[2][2] = {{3, -1}, {0, 1}};
  long long r[2][2];
  pow(m, x, r);
  sum += (vs[0] + vs[n - 1]) % M * ((r[0][0] + r[0][1]) % M) % M;
  sum %= M;
  long long m2[2][2] = {{1, 1}, {1, 0}};
  sum += M - vs[0];
  sum %= M;
  pow(m2, x, r);
  long long h = vs[n - 1] * r[0][0] % M + vs[n - 2] * r[0][1] % M;
  h %= M;
  sum += M - h;
  sum %= M;
  sum = sum * powmod(3, y, M) % M;
  pow(m, y, r);
  sum += (vs[0] + h) % M * ((r[0][0] + r[0][1]) % M) % M;
  sum %= M;
  printf("%lld\n", sum);
  return 0;
}
