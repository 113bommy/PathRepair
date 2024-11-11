#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
struct mat {
  int n, m;
  vector<vector<int> > M;
  mat(int x, int y) {
    n = x;
    m = y;
    vector<int> T;
    for (int i = 0; i < m; i++) {
      T.push_back(0);
    }
    for (int i = 0; i < n; i++) {
      M.push_back(T);
    }
  }
};
inline ll prod(ll a, ll b) { return (a * b) % MOD; }
inline ll prod2(ll a, ll b) { return (a * b) % (MOD - 1); }
ll powe(ll b, ll e) {
  ll res = 1;
  while (e) {
    if (e % 2) res = prod(res, b);
    b = prod(b, b);
    e /= 2;
  }
  return res;
}
mat mult(mat A, mat B) {
  mat R(A.m, B.n);
  for (int i = 0; i < A.n; i++) {
    for (int j = 0; j < B.m; j++) {
      for (int k = 0; k < A.m; k++) {
        R.M[i][j] += prod2(A.M[i][k], B.M[k][j]);
        if (R.M[i][j] >= MOD - 1) R.M[i][j] -= MOD - 1;
      }
    }
  }
  return R;
}
mat pot(mat A, ll e) {
  int n = A.n;
  mat R(n, n);
  for (int i = 0; i < n; i++) {
    R.M[i][i] = 1;
  }
  while (e) {
    if (e % 2) R = mult(R, A);
    A = mult(A, A);
    e /= 2;
  }
  return R;
}
int red(int x) {
  while (x < 0) {
    x += MOD - 1;
  }
  return x;
}
int main() {
  ll n, f1, f2, f3, c;
  scanf("%lld %lld %lld %lld %lld", &n, &f1, &f2, &f3, &c);
  int empuja = n - 3;
  mat primera(3, 3);
  primera.M[0][0] = 1;
  primera.M[0][1] = 1;
  primera.M[0][2] = 1;
  primera.M[1][0] = 1;
  primera.M[2][1] = 1;
  primera = pot(primera, empuja);
  mat segunda(5, 5);
  segunda.M[0][0] = 1;
  segunda.M[0][1] = 1;
  segunda.M[0][2] = 1;
  segunda.M[0][3] = 2;
  segunda.M[0][4] = red(-4);
  segunda.M[1][0] = 1;
  segunda.M[2][1] = 1;
  segunda.M[3][3] = 1;
  segunda.M[3][4] = 1;
  segunda.M[4][4] = 1;
  segunda = pot(segunda, empuja);
  mat vec1(3, 1);
  mat vec2(3, 1);
  mat vec3(3, 1);
  mat vec4(5, 1);
  vec1.M[2][0] = 1;
  vec2.M[1][0] = 1;
  vec3.M[0][0] = 1;
  vec4.M[4][0] = 1;
  vec4.M[3][0] = 3;
  ll res = 1;
  vec1 = mult(primera, vec1);
  ll pot1 = vec1.M[0][0];
  res = prod(res, powe(f1, pot1));
  vec2 = mult(primera, vec2);
  ll pot2 = vec2.M[0][0];
  res = prod(res, powe(f2, pot2));
  vec3 = mult(primera, vec3);
  ll pot3 = vec3.M[0][0];
  res = prod(res, powe(f3, pot3));
  vec4 = mult(segunda, vec4);
  ll pot4 = vec4.M[0][0];
  res = prod(res, powe(c, pot4));
  printf("%lld\n", res);
}
