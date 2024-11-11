#include <bits/stdc++.h>
using namespace std;
const int infi = 1e9;
const long long int infl = 1e18;
const int MOD = 1e9 + 7;
long long int log_2(long long int n) {
  return (n > 1ll) ? 1ll + log_2(n / 2) : 0ll;
}
inline void add(long long int &a, long long int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline void sub(long long int &a, long long int b) {
  a -= b;
  if (a < 0) a += MOD;
}
inline string IntToString(long long int a) {
  char x[100];
  sprintf(x, "%lld", a);
  string s = x;
  return s;
}
inline long long int StringToInt(string a) {
  char x[100];
  long long int res;
  strcpy(x, a.c_str());
  sscanf(x, "%lld", &res);
  return res;
}
inline string GetString(void) {
  char x[1000005];
  scanf("%s", x);
  string s = x;
  return s;
}
inline string uppercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}
inline string lowercase(string s) {
  int n = (int)s.size();
  for (int(i) = (0); (i) < (n); ++(i))
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}
inline void OPEN(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
void showarr(long long int arr[], long long int n) {
  int i;
  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}
void showvec(vector<long long int> v) {
  int i;
  for (i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}
int isPalindrome(string str) {
  int l = 0;
  int h = str.length() - 1;
  while (h > l) {
    if (str[l++] != str[h--]) {
      return 0;
    }
  }
  return 1;
}
void showvecpair(vector<pair<long long int, long long int> > v) {
  for (int i = 0; i < (int)v.size(); i++) {
    cout << v[i].first << " " << v[i].second << endl;
  }
}
bool sortbysec(const pair<long long int, long long int> &a,
               const pair<long long int, long long int> &b) {
  return (a.second < b.second);
}
void bin(unsigned n) {
  unsigned i;
  for (i = 1 << 31; i > 0; i = i / 2) (n & i) ? printf("1") : printf("0");
}
long long int cntset(long long int n) {
  bitset<64> b1(n);
  return b1.count();
}
long long int setBitNumber(long long int n) {
  if (n == 0) return 0;
  long long int msb = 0;
  n = n / 2;
  while (n != 0) {
    n = n / 2;
    msb++;
  }
  return (msb);
}
long long int p[100005];
void seive() {
  long long int i, j;
  for (i = 0; i < 100005; i++) p[i] = i;
  for (i = 2; i <= sqrt(100005); i++) {
    if (p[i] != i) continue;
    for (j = i * i; j < 100005; j += i) {
      if (p[j] == j) p[j] = i;
    }
  }
  return;
}
long long int power(long long int n, long long int x) {
  long long int j = n, prod = 1;
  while (x) {
    if (x % 2) {
      prod = ((prod % MOD) * (j % MOD)) % MOD;
    }
    j = (j * j) % MOD;
    x = x / 2;
  }
  return prod;
}
long long int fact(long long int n) {
  long long int i, prod = 1;
  for (i = 1; i <= n; i++) {
    prod = (prod * i) % MOD;
  }
  return prod;
}
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
void solve() {
  long long int m, n, l, a, b, i, Max = INT_MIN, Min = INT_MAX, ctr = 0,
                                  cnt = 0, x, y, prod = 1, low, high, Max1,
                                  Max2;
  string s;
  cin >> s;
  n = 0;
  for (i = 0; i < s.size(); i++) {
    n = n + (s[i] - '0');
  }
  if (s.size() == 1)
    cnt = 0;
  else
    cnt = 1;
  long long int sum = 0;
  while (n > 9) {
    sum = 0;
    while (n != 0) {
      sum = sum + n % 10;
      n = n / 10;
    }
    cnt++;
    if (sum <= 9)
      break;
    else
      n = sum;
  }
  cout << cnt << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, T;
  T = 1;
  for (i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
