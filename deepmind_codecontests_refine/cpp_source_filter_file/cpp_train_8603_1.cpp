#include <bits/stdc++.h>
using namespace std;
vector<long long int> vec, pec;
vector<pair<long long int, long long int> > vp;
long long int maxi, mini;
set<char> st;
map<long long int, long long int> has;
string strng[200005];
int mat[5236][10];
const long long int K = 2LL;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const long double pi = 3.1415926535897;
long long int ar[500002], br[512346];
const long long int MOD = 1e9 + 7;
inline long long int powr(long long int a, long long int b) {
  if (b == 0) return 1;
  long long int x = powr(a, b / 2);
  if (b % 2 == 0)
    return (x * x) % MOD;
  else
    return (((x * x) % MOD) * a) % MOD;
}
inline long long int inv(long long int x) { return powr(x, MOD - 2); }
vector<vector<long long int> > mul(vector<vector<long long int> > A,
                                   vector<vector<long long int> > B) {
  if (0) {
    cout << "Working fine!!!";
  }
  vector<vector<long long int> > C(K + 1, vector<long long int>(K + 1));
  for (int i = 1; i <= K; i++)
    for (int j = 1; j <= K; j++)
      for (int k = 1; k <= K; k++)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
  return C;
}
vector<vector<long long int> > pow(vector<vector<long long int> > A,
                                   long long int p) {
  if (p == 1) return A;
  if (0) {
    cout << "Working fine!!!";
  }
  if (p % 2) return mul(A, pow(A, p - 1));
  vector<vector<long long int> > X = pow(A, p / 2);
  return mul(X, X);
}
long long int solve(long long int N, long long int d, long long int I) {
  vector<long long int> F1(K + 1);
  F1[1] = 1LL;
  F1[2] = (d * inv(I)) % MOD;
  vector<vector<long long int> > T(K + 1, vector<long long int>(K + 1));
  T[1][1] = 0LL, T[1][2] = 1LL;
  if (0) {
    cout << "Working fine!!!";
  }
  T[2][1] = -1LL, T[2][2] = (2 * d * inv(I)) % MOD;
  if (N == 1) return (d * inv(I)) % MOD;
  T = pow(T, N - 1);
  long long int res = 0;
  for (int i = 1; i <= K; i++) res = (res + T[1][i] * F1[i]) % MOD;
  return res;
}
void multi(long long int a[2][2], long long int b[2][2]) {
  long long int mul[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      mul[i][j] = 0;
      for (int k = 0; k < 2; k++)
        mul[i][j] =
            (mul[i][j] % MOD + (a[i][k] % MOD * b[k][j] % MOD) % MOD) % MOD;
    }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) a[i][j] = mul[i][j];
}
long long int mat_power(long long int F[2][2], long long int n, long long int d,
                        long long int i) {
  long long int a = (2 * d % MOD * inv(i) % MOD) % MOD;
  long long int M[2][2] = {{a, -1}, {1, 0}};
  long long int b = (d % MOD * inv(i) % MOD) % MOD;
  if (n == 1) return ((b % MOD * F[0][0] % MOD) % MOD + F[0][1] % MOD) % MOD;
  long long int ret = mat_power(F, n / 2, d, i);
  multi(F, F);
  if (n % 2 != 0) multi(F, M);
  return ((b % MOD * F[0][0] % MOD) % MOD + F[0][1] % MOD) % MOD;
}
long long int solve_100(long long int n, long long int d, long long int i) {
  long long int a = (2 * d % MOD * inv(i) % MOD) % MOD;
  long long int b = (d % MOD * inv(i) % MOD) % MOD;
  long long int F[2][2] = {{a, -1}, {1, 0}};
  if (n == 2) return b;
  return mat_power(F, n - 2, d, i);
}
int main() {
  long long int c, i, p, q, d, k, len, y, j, a, b, t,
      ans = 0, flag = 0, n, m, g = 0, res = 0, sum = 0, e, f, r, minm, maxm, x,
      hr, secmaxm, z, s, o, test;
  c = 0;
  string str, ptr = "", dtr;
  char ch, col;
  set<char>::iterator it, jt;
  cin >> n >> k;
  cin >> str;
  len = str.length();
  for (i = 0; i < len; i++) st.insert(str[i]);
  jt = st.begin();
  if (k == n) {
    r = 0;
    for (i = n - 1; i >= 0; i--) {
      it = st.upper_bound(str[i]);
      r++;
      if (it != st.end() && flag == 0) {
        ptr += (*it);
        j = r - 1;
        flag = 1;
      } else
        ptr += str[i];
    }
    for (i = j - 1; i >= 0; i--) ptr[i] = (*jt);
    reverse(ptr.begin(), ptr.end());
    for (i = n; i < k; i++) ptr += (*jt);
    cout << ptr;
  } else if (k < n) {
    r = 0;
    for (i = n - 1; i >= 0; i--) {
      it = st.upper_bound(str[i]);
      r++;
      if (it != st.end() && flag == 0) {
        ptr += (*it);
        j = r - 1;
        flag = 1;
      } else
        ptr += str[i];
    }
    for (i = j - 1; i >= 0; i--) ptr[i] = (*jt);
    reverse(ptr.begin(), ptr.end());
    for (i = 0; i < k; i++) cout << ptr[i];
  } else {
    for (i = n; i < k; i++) str += (*jt);
    cout << str;
  }
  return 0;
}
