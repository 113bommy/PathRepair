#include <bits/stdc++.h>
using namespace std;
long long int modulo;
vector<vector<long long int> > operator*(vector<vector<long long int> > m1,
                                         vector<vector<long long int> > m2) {
  vector<vector<long long int> > r(2, vector<long long int>(2, 0));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        r[i][j] = (r[i][j] + m1[i][k] * m2[k][j]) % modulo;
  return r;
}
vector<long long int> operator*(vector<vector<long long int> > m,
                                vector<long long int> v) {
  vector<long long int> r(2, 0);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) r[i] = (r[i] + m[i][j] * v[j]) % modulo;
  return r;
}
vector<vector<long long int> > eleva(vector<vector<long long int> > m,
                                     long long int e) {
  if (e == 0) {
    vector<vector<long long int> > r(2, vector<long long int>(2, 0));
    for (int i = 0; i < 2; i++) r[i][i] = 1;
    return r;
  }
  if (e % 2 == 0) return eleva(m * m, e / 2);
  return m * eleva(m * m, e / 2);
}
long long int eleva(long long int b, long long int e) {
  if (e == 0) return 1 % modulo;
  if (e % 2 == 0) return eleva(b * b % modulo, e / 2);
  return b * eleva(b * b % modulo, e / 2) % modulo;
}
void escribe(vector<vector<long long int> > m) {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) cout << " " << m[i][j];
    cout << endl;
  }
}
long long int n, k, l;
int main() {
  cin >> n >> k >> l >> modulo;
  long long int kk = k;
  long long int maneras = 1;
  vector<vector<long long int> > m(2, vector<long long int>(2, 1));
  m[1][1] = 0;
  vector<long long int> v(2, 0);
  v[0] = 1;
  vector<long long int> res = eleva(m, n) * v;
  long long int maneras0 = (res[0] + res[1]) % modulo;
  long long int maneras1 =
      ((eleva(2, n) - maneras0) % modulo + modulo) % modulo;
  for (int b = 0; b < l; b++) {
    if (k & (1LL << b))
      maneras = (maneras * maneras1) % modulo;
    else
      maneras = (maneras * maneras0) % modulo;
    kk >>= 1;
  }
  if (kk)
    cout << 0 << endl;
  else
    cout << maneras << endl;
}
