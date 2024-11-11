#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 5001;
int p[SIZE];
vector<int> pp;
void prime_init() {
  for (int i = 2; i < SIZE; i++) {
    if (!p[i]) {
      pp.push_back(i);
      for (int j = i; j < SIZE; j += i) {
        if (!p[j]) p[j] = i;
      }
    }
  }
}
bool is_prime(int x) { return p[x] == x; }
long long cnt[SIZE];
int fac_num[SIZE];
int sp[SIZE];
int dis[SIZE][SIZE];
vector<int> fac[SIZE];
int ord[SIZE];
int dp[SIZE][SIZE];
bool cmp(int x, int y) { return fac[x] < fac[y]; }
int main() {
  prime_init();
  int n;
  R(n);
  for (int i = 0; i < (n); ++i) {
    int x;
    R(x);
    cnt[x]++;
  }
  for (int i = 0; i < (SIZE); ++i) fac[i].resize(((int)(pp).size()));
  for (int i = 0; i < (SIZE); ++i) ord[i] = i;
  for (int i = (2); i < (SIZE); ++i) {
    for (int j = 0; j < (((int)(pp).size())); ++j) fac[i][j] = fac[i - 1][j];
    int me = i;
    fac_num[i] = fac_num[i - 1];
    for (int j = 0; j < (((int)(pp).size())); ++j) {
      int x = pp[j];
      while (me % x == 0) {
        me /= x;
        fac_num[i]++;
        fac[i][((int)(pp).size()) - 1 - j]++;
      }
    }
  }
  sort(ord, ord + SIZE, cmp);
  for (int i = (1); i < (SIZE); ++i) {
    int now = 0;
    for (int j = 0; j < (((int)(pp).size())); ++j) {
      if (fac[ord[i]][j] == fac[ord[i - 1]][j])
        now += fac[ord[i]][j];
      else {
        now += min(fac[ord[i]][j], fac[ord[i - 1]][j]);
        break;
      }
    }
    dp[i - 1][i] = now;
  }
  for (int i = 0; i < (SIZE); ++i) {
    for (int j = (i + 2); j < (SIZE); ++j) {
      dp[i][j] = min(dp[i][j - 1], dp[j - 1][j]);
    }
  }
  for (int i = 0; i < (SIZE); ++i) {
    int x = ord[i];
    for (int j = (i + 1); j < (SIZE); ++j) {
      int y = ord[j];
      dis[y][x] = dis[x][y] = fac_num[x] + fac_num[y] - dp[i][j] * 2;
    }
  }
  long long an = 1e18;
  for (int i = 0; i < (SIZE); ++i) {
    long long now = 0;
    for (int j = 0; j < (SIZE); ++j) {
      now += cnt[j] * dis[i][j];
    }
    an = min(an, now);
  }
  W(an);
  return 0;
}
