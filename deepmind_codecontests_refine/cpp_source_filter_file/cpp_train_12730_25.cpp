#include <bits/stdc++.h>
using namespace std;
long long day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long dx[] = {0, 1, 0, -1};
long long dy[] = {1, 0, -1, 0};
const string SP = " ";
const string TAB = "\t";
const long long MOD = 1000000007LL;
bool isupper(char c) {
  if ('A' <= c && c <= 'Z') return 1;
  return 0;
}
bool islower(char c) {
  if ('a' <= c && c <= 'z') return 1;
  return 0;
}
bool isnumber(char c) { return ('0' <= c && c <= '9'); }
bool isalpha(char c) { return (isupper(c) || islower(c)); }
bool is_kaibun(string s) {
  string rs = s;
  reverse((rs).begin(), (rs).end());
  if (s == rs)
    return true;
  else
    return false;
}
template <typename T>
void printv(vector<T> v, bool is_endl = true) {
  for (long long i = 0; i < v.size(); i++) {
    if (i) cout << " ";
    cout << v[i];
  }
  if (is_endl) cout << endl;
}
template <typename T>
void printendl(vector<T> v) {
  for (auto date : v) cout << date << endl;
}
template <typename T>
void printvv(vector<vector<T>> v) {
  for (long long i = 0; i < v.size(); i++) {
    for (long long j = 0; j < v[i].size(); j++) {
      if (j) cout << " ";
      cout << v[i][j];
    }
    cout << endl;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool isPrime(long long x) {
  if (x == 1) return 0;
  if (x == 2) return 1;
  for (long long i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
vector<string> split(string s, char c) {
  if (s[s.size() - 1] != c) s += c;
  vector<string> v;
  long long pos = 0;
  for (long long i = (long long)0; i < (long long)s.size(); i++) {
    if (s[i] == c) {
      v.push_back(s.substr(pos, i - pos));
      pos = i + 1;
    }
    if (i == s.size() - 1 && s.substr(pos, i - pos) != "")
      v.push_back(s.substr(pos, i - pos));
  }
  return v;
}
long long f(long long x, long long n) {
  long long ret = 0;
  while (x) {
    ret += x;
    x /= 2;
    if (ret == n) return n;
  }
  return ret;
}
signed main() {
  long long n;
  cin >> n;
  for (long long i = (long long)0; i < (long long)n; i++) {
    long long x;
    cin >> x;
    for (long long j = (long long)0; j < (long long)x; j++) {
      if (j) cout << " ";
      cout << 2 * j + 1;
    }
    cout << endl;
  }
}
