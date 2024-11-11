#include <bits/stdc++.h>
using namespace std;
template <typename T>
T in() {
  char ch;
  T n = 0;
  bool ng = false;
  while (1) {
    ch = getchar();
    if (ch == '-') {
      ng = true;
      ch = getchar();
      break;
    }
    if (ch >= '0' && ch <= '9') break;
  }
  while (1) {
    n = n * 10 + (ch - '0');
    ch = getchar();
    if (ch < '0' || ch > '9') break;
  }
  return (ng ? -n : n);
}
template <typename T>
inline T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
inline T Gcd(T a, T b) {
  if (a < 0) return Gcd(-a, b);
  if (b < 0) return Gcd(a, -b);
  return (b == 0) ? a : Gcd(b, a % b);
}
template <typename T>
inline T Lcm(T a, T b) {
  if (a < 0) return Lcm(-a, b);
  if (b < 0) return Lcm(a, -b);
  return a * (b / Gcd(a, b));
}
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
bool isVowel(char ch) {
  ch = toupper(ch);
  if (ch == 'A' || ch == 'U' || ch == 'I' || ch == 'O' || ch == 'E')
    return true;
  return false;
}
template <typename T>
long long int isLeft(T a, T b, T c) {
  return (a.x - b.x) * (b.y - c.y) - (b.x - c.x) * (a.y - b.y);
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
bool isConst(char ch) {
  if (isalpha(ch) && !isVowel(ch)) return true;
  return false;
}
int toInt(string s) {
  int sm;
  stringstream second(s);
  second >> sm;
  return sm;
}
map<long long int, int> mp;
long long int a[500007];
vector<long long int> A[500007];
set<pair<long long int, long long int> > no;
int ln, p;
int isok() {
  if (no.size() > (ln - p)) return 0;
  set<pair<long long int, long long int> >::iterator it;
  int i = 1;
  for (it = no.begin(); it != no.end(); it++, i++) {
    if (A[i][A[i].size() - 1] + 1 >= (it->first * -1))
      continue;
    else
      return 0;
  }
  return 1;
}
int main() {
  int n;
  n = in<int>();
  for (int i = 1; i < n + 1; i++) a[i] = in<long long int>(), mp[a[i]]++;
  sort(a + 1, a + n + 1);
  ln = 0;
  for (int cs = 1; cs <= n + 1; cs++) {
    long long int nw = 1;
    int f = 0;
    long long int sm = 0;
    while (mp[nw] > 0) {
      A[cs].push_back(nw);
      sm += nw;
      mp[nw]--;
      nw *= 2;
      f = 1;
    }
    if (!f) {
      ln = cs - 1;
      break;
    }
    A[cs].push_back(sm);
  }
  int ps = 0;
  for (int i = 1; i < n + 1; i++) {
    long long int nw = a[i];
    while (mp[nw]) {
      no.insert(make_pair(-nw, ps++));
      mp[nw]--;
    }
  }
  vector<int> an;
  if (isok()) {
    an.push_back(ln);
  }
  p = 0;
  int lo = 2, hi = ln;
  int ans = ln + 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    p = (ln - mid + 1);
    int id = ps;
    for (int i = mid; i <= ln; i++) {
      for (int j = 0; j < A[i].size() - 1; j++)
        no.insert(make_pair(-A[i][j], id++));
    }
    if (isok()) {
      hi = mid - 1;
      ans = mid;
    } else
      lo = mid + 1;
    id = ps;
    for (int i = mid; i <= ln; i++) {
      for (int j = 0; j < A[i].size() - 1; j++)
        no.erase(make_pair(-A[i][j], id++));
    }
  }
  for (int i = ans; i <= ln; i++) {
    an.push_back(i - 1);
  }
  sort(an.begin(), an.end());
  if (an.size() == 0) cout << "-1\n";
  for (int i = 0; i < an.size(); i++) printf("%d ", an[i]);
  return 0;
}
