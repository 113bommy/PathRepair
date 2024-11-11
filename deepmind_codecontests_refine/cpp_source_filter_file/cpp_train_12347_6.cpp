#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << '{';
  for (int i = (0), __i = (((int)(vec).size())); i < __i; i++) {
    os << vec[i];
    if (i + 1 != ((int)(vec).size())) os << ',';
  }
  os << '}';
  return os;
}
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &par) {
  os << '(' << par.first << ',' << par.second << ')';
  return os;
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
template <class T>
T sqr(T x) {
  return x * x;
}
bool simple[1000010];
long long factor[200];
long long cnt[1000010];
long long prod[1000010];
map<long long, long long> factN, factM, factS;
vector<long long> fact[3];
long long get_val(long long cur, long long maxval, int f) {
  if (cur > maxval) return 0;
  if (f == ((int)(fact[2]).size())) return 1;
  long long res = 0;
  for (int i = (0), __i = (factS[fact[2][f]] + 1); i < __i; i++) {
    res += get_val(cur, maxval, f + 1);
    cur *= fact[2][f];
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  cnt[0] = 0;
  for (int i = (1), __i = (1000010); i < __i; i++) {
    cnt[i] = cnt[i & (i - 1)] + 1;
    simple[i] = true;
  }
  int f = 0;
  for (int i = (2), __i = (1000010); i < __i; i++) {
    if (simple[i]) {
      if (i < 1000) factor[f++] = i;
      for (int j = 2 * i; j < 1000010; j += i) simple[j] = false;
    }
  }
  for (int t = (0), __t = (T); t < __t; t++) {
    long long n[4], m[4], s[4];
    cin >> n[1] >> n[2] >> n[3];
    cin >> m[1] >> m[2] >> m[3];
    cin >> s[1] >> s[2] >> s[3];
    s[1] *= 2;
    long long N = n[0] = n[1] * n[2] * n[3];
    long long M = m[0] = m[1] * m[2] * m[3];
    long long S = s[0] = s[1] * s[2] * s[3];
    factN.clear();
    factM.clear();
    factS.clear();
    fact[0].clear();
    fact[1].clear();
    fact[2].clear();
    for (int i = (0), __i = (f); i < __i; i++) {
      for (int j = (1), __j = (4); j < __j; j++) {
        while ((n[j] % factor[i]) == 0) {
          if (factN[factor[i]]++ == 0) fact[0].push_back(factor[i]);
          n[j] /= factor[i];
          N /= factor[i];
        }
        while ((m[j] % factor[i]) == 0) {
          if (factM[factor[i]]++ == 0) fact[1].push_back(factor[i]);
          m[j] /= factor[i];
          M /= factor[i];
        }
        while ((s[j] % factor[i]) == 0) {
          if (factS[factor[i]]++ == 0) fact[2].push_back(factor[i]);
          s[j] /= factor[i];
          S /= factor[i];
        }
      }
    }
    sort(n + 1, n + 4);
    sort(m + 1, m + 4);
    sort(s + 1, s + 4);
    for (int j = (1), __j = (4); j < __j; j++) {
      if (n[j] > 1) {
        fact[0].push_back(n[j]);
        factN[n[j]]++;
      }
      if (m[j] > 1) {
        fact[1].push_back(m[j]);
        factM[m[j]]++;
      }
      if (s[j] > 1) {
        fact[2].push_back(s[j]);
        factS[s[j]]++;
      }
    }
    vector<long long> a;
    int j = 0;
    for (int i = (0), __i = (((int)(fact[0]).size())); i < __i; i++) {
      while (j < ((int)(fact[2]).size()) && fact[2][j] < fact[0][i]) j++;
      if (j == ((int)(fact[2]).size()) || fact[2][j] > fact[0][i])
        a.push_back(fact[0][i]);
      else if (factN[fact[0][i]] > factS[fact[0][i]])
        a.push_back(pow((long long)fact[0][i], factS[fact[0][i]] + 1));
    }
    prod[0] = 1;
    for (int i = (0), __i = (((int)(a).size())); i < __i; i++)
      prod[1LL << i] = a[i];
    long long res = m[0];
    for (int i = (1), __i = (1LL << ((int)(a).size())); i < __i; i++) {
      prod[i] = prod[i & (i - 1)] * prod[i & ~(i - 1)];
      if (cnt[i] % 2)
        res -= m[0] / prod[i];
      else
        res += m[0] / prod[i];
    }
    res += get_val(1, n[0], 0);
    cout << res << endl;
  }
  return 0;
}
