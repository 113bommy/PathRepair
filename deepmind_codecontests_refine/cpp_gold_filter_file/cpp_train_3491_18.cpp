#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const int MN = 100002;
long long int pw(long long int x, long long int n) {
  if (n == 0) return 1;
  long long int tmp = pw(x, n / 2);
  if (n % 2)
    return (tmp * tmp % mod) * x % mod;
  else
    return tmp * tmp % mod;
}
long long int mod_inv(long long int x) { return pw(x, mod - 2); }
int M;
string st;
long long int C;
vector<long long int> pw1, pw2, pw3, inv_pw2;
void fill_pw() {
  pw1.resize(MN);
  pw1[0] = 1;
  for (int i = 1; i < MN; i++) {
    pw1[i] = pw1[i - 1] * 25 % mod;
  }
  pw2.resize(MN);
  pw2[0] = 1;
  for (int i = 1; i < MN; i++) {
    pw2[i] = pw2[i - 1] * 26 % mod;
  }
  inv_pw2.resize(MN);
  for (int i = 0; i < MN; i++) {
    inv_pw2[i] = mod_inv(pw2[i]);
  }
  pw3.resize(MN);
  pw3[0] = 1;
  for (int i = 1; i < MN; i++) {
    pw3[i] = pw3[i - 1] * C % mod;
  }
}
vector<long long int> fct, inv_fct;
void fill_fct() {
  fct.resize(MN);
  fct[0] = 1;
  for (int i = 1; i < MN; i++) {
    fct[i] = fct[i - 1] * (long long int)i % mod;
  }
  inv_fct.resize(MN);
  for (int i = 0; i < MN; i++) {
    inv_fct[i] = mod_inv(fct[i]);
  }
}
vector<pair<int, int> > qur;
vector<int> X;
map<int, int> dx;
vector<long long int> ans;
vector<int> id;
vector<int> inv;
void get_pre() {
  int pos = 0;
  for (int i = 0; i < X.size(); i++) {
    long long int val = 0;
    for (int j = X[i] - 1; j < MN; j++) {
      long long int cmb = fct[j] * inv_fct[X[i] - 1] % mod;
      cmb *= inv_fct[j - X[i] + 1];
      cmb %= mod;
      long long int tmp = cmb * pw1[j - X[i] + 1] % mod;
      tmp *= inv_pw2[j - X[i] + 1];
      tmp %= mod;
      val += tmp;
      val %= mod;
      while (pos < qur.size() && pair<int, int>(X[i], j + 1) > qur[pos]) {
        pos++;
      }
      while (pos < qur.size() && qur[pos].first == X[i] &&
             qur[pos].second - 1 == j) {
        ans[pos] = val;
        pos++;
      }
    }
  }
}
bool cmp(int a, int b) { return qur[a] < qur[b]; }
int main() {
  C = 25 * mod_inv(26) % mod;
  fill_pw();
  fill_fct();
  scanf("%d", &M);
  cin >> st;
  X.push_back(st.size());
  for (int i = 0; i < M; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      st.clear();
      cin >> st;
      X.push_back(st.size());
    } else {
      int n;
      scanf("%d", &n);
      qur.push_back(pair<int, int>(st.size(), n));
    }
  }
  sort(X.begin(), X.end());
  X.resize(unique(X.begin(), X.end()) - X.begin());
  for (int i = 0; i < X.size(); i++) dx[X[i]] = i;
  id.resize(qur.size());
  for (int i = 0; i < qur.size(); i++) id[i] = i;
  sort(id.begin(), id.end(), cmp);
  sort(qur.begin(), qur.end());
  inv.resize(qur.size());
  for (int i = 0; i < qur.size(); i++) inv[id[i]] = i;
  ans = vector<long long int>(qur.size(), 0);
  get_pre();
  for (int i = 0; i < qur.size(); i++) {
    int l = qur[inv[i]].first, n = qur[inv[i]].second;
    if (l > n)
      printf("0\n");
    else
      printf("%I64d\n", pw2[n - l] * ans[inv[i]] % mod);
  }
}
