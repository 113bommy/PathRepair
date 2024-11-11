#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "avx,avx2,fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
long long MOD = 1e9 + 7;
long long modd = MOD * MOD;
vector<vector<long long> > mult(vector<vector<long long> > a1,
                                vector<vector<long long> > a2) {
  long long nn = a1.size();
  vector<vector<long long> > aa(nn);
  for (int i = 0; i < nn; i++) {
    aa[i].resize(nn);
    for (int j = 0; j < nn; j++) {
      long long anss = MOD * MOD;
      for (int k = 0; k < nn; k++) {
        anss = min(anss, (a1[i][k] + a2[k][j]));
      }
      aa[i][j] = anss;
    }
  }
  return aa;
}
vector<vector<long long> > e;
void init_mat(long long n) {
  e.resize(n);
  for (int i = 0; i < n; i++) {
    e[i].resize(n, MOD * MOD);
    e[i][i] = 0;
  }
}
vector<vector<long long> > binpow(vector<vector<long long> > a, long long n) {
  if (n == 0) return e;
  if (n % 2 == 1)
    return mult(binpow(a, n - 1), a);
  else {
    vector<vector<long long> > b = binpow(a, n / 2);
    return mult(b, b);
  }
}
set<long long> AA[4][4][12];
bool ch(vector<vector<long long> > A, long long k) {
  long long kk = MOD * MOD;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      kk = min(A[i][j], kk);
    }
  }
  return kk < k;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0),
      cout << fixed << setprecision(20);
  init_mat(4);
  long long n;
  string t;
  cin >> n >> t;
  vector<vector<long long> > A(4);
  for (int i = 0; i < 4; i++) A[i].resize(4);
  for (int i = 0; i < t.size(); i++) {
    long long tt = 0;
    for (int j = i; j < min((long long)i + 12, (long long)t.size()); j++) {
      tt *= 4;
      tt += t[j] - 'A';
      if (j > i) AA[t[i] - 'A'][t[j] - 'A'][j - i - 1].insert(tt);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      for (int u = 0; u < 12; u++) {
        if (AA[i][j][u].size() < pow(4, u)) {
          A[i][j] = u + 1;
          break;
        }
      }
    }
  }
  long long L = 0, R = n + 1;
  while (R - L > 1) {
    long long mid = (R + L) / 2;
    if (ch(binpow(A, mid - 1), n)) {
      L = mid;
    } else {
      R = mid;
    }
  }
  cout << L;
}
