#include <bits/stdc++.h>
using namespace std;
long long day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
long long dx[] = {0, 1, 0, -1};
long long dy[] = {1, 0, -1, 0};
struct edge {
  long long to, cost;
};
bool isupper(char c) {
  if ('A' <= c && c <= 'Z') return 1;
  return 0;
}
bool islower(char c) {
  if ('a' <= c && c <= 'z') return 1;
  return 0;
}
bool isPrime(long long x) {
  if (x == 1) return 0;
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (long long i = 3; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
bool iskaibun(string s) {
  for (long long i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - i - 1]) return 0;
  return 1;
}
bool isnumber(char c) { return ('0' <= c && c <= '9'); }
bool isalpha(char c) { return (isupper(c) && islower(c)); }
void printvi(vector<long long> v) {
  for (long long i = (long long)0; i < (long long)v.size(); i++) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}
void printvil(vector<long long> v) {
  for (long long i = (long long)0; i < (long long)v.size(); i++) {
    cout << v[i] << endl;
  }
}
void printvvi(vector<vector<long long>> v) {
  for (long long i = (long long)0; i < (long long)v.size(); i++) {
    for (long long j = (long long)0; j < (long long)v[i].size(); j++) {
      if (j) cout << " ";
      cout << v[i][j];
    }
    cout << endl;
  }
}
void printvstr(vector<string> v) {
  for (long long i = (long long)0; i < (long long)v.size(); i++) {
    cout << v[i] << endl;
  }
}
struct S {
  long long score, id;
};
signed main() {
  long long n;
  cin >> n;
  vector<vector<long long>> v(n, vector<long long>(n));
  for (long long i = (long long)0; i < (long long)n; i++)
    for (long long j = (long long)0; j < (long long)n; j++) cin >> v[i][j];
  long long sum = 0;
  for (long long i = (long long)0; i < (long long)n; i++) {
    sum += v[i][i];
    sum += v[n - i - 1][n - i - 1];
  }
  for (long long i = (long long)0; i < (long long)n; i++) {
    sum += v[(n - 1) / 2][i];
    sum += v[i][(n - 1) / 2];
  }
  sum -= 3 * v[(n - 1) / 2][(n - 1) / 2];
  cout << sum << endl;
}
