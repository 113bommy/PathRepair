#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;

vvi mult(vvi A, vvi B, ll mod) {
  ll n = A.size();
  vvi C(n, vi(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        C[i][j] += A[i][k] * B[k][j];
        C[i][j] %= mod;
      }
    }
  }
  return C;
}

vvi pow(vvi A, ll x, ll mod) {
  vvi tmp = A;
  vvi ans = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  while(x) {
    if (x % 2) {
      ans = mult(ans, tmp, mod);
    }
    tmp = mult(tmp, tmp, mod);
    x /= 2;
  }
  return ans;
}

int main() {
  ll L, A, B, M;
  cin >> L >> A >> B >> M;

  ll X = 0;
  ll s = A;

  for (ll d = 1; d <= 18; d++) {
    ll C = [&](){
      ll p = 0;
      for (ll i = 0; i < d - 1; i++) {
        p = p * 10 + 9;
      }
      ll q = p * 10 + 9;

      // p < A + B * i <= q
      // (p - A) / B < i <= (q - A) / B
      q = q - A < 0 ? -1 : (q - A) / B;
      p = (p - A + B) / B;
      q = min(q, L - 1);
      p = max(p, 0ll);
      ll C = max(0ll, q - p + 1);
      return C;
    }();

    vvi A = {
      {([&](){ ll i = 1; for (ll j = 0; j < d; j++) i = i * 10 % M; return i; })(), 0, 0},
      {1, 1, 0},
      {0, B % M, 1},
    };

    vvi B = pow(A, C, M);

    tie(X, s) = [&](){
      ll X_new = X * B[0][0] + s * B[1][0] + 1 * B[2][0];
      ll s_new = X * B[0][1] + s * B[1][1] + 1 * B[2][1];
      X_new %= M;
      s_new %= M;
      return make_pair(X_new, s_new);
    }();
  }

  cout << X << endl;
}
