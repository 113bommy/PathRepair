#include <bits/stdc++.h>
using namespace std;
long long add(long long a, long long b, long long m) {
  long long x = a + b;
  while (x >= m) x -= m;
  return x;
}
long long sub(long long a, long long b, long long m) {
  long long x = a - b;
  while (x < 0) x += m;
  return x;
}
long long mul(long long a, long long b, long long m) {
  long long x = a * b;
  x %= m;
  return x;
}
long long powermod(long long _a, long long _b, long long _m = 1000000007) {
  long long _r = 1;
  while (_b) {
    if (_b % 2 == 1) _r = (_r * _a) % _m;
    _b /= 2;
    _a = (_a * _a) % _m;
  }
  return _r;
}
string s1, s2;
bool mar[200001];
bool isSubSequence(string str1, string str2, int m, int n) {
  int j = 0;
  for (int i = 0; i < n && j < m; i++)
    if (str1[j] == str2[i]) j++;
  return (j == m);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s1 >> s2;
  int a[s1.length()];
  for (long long i = 0; i < s1.length(); i++) cin >> a[i];
  int l = 0, r = s1.length() - 1;
  int ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    string temp = s1;
    for (long long i = 0; i < mid + 1; i++) temp[a[i] - 1] = '?';
    if (isSubSequence(s2, temp, s2.length(), temp.length())) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans + 1 << endl;
  return 0;
}
