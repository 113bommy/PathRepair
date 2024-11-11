#include <bits/stdc++.h>
using namespace std;
template <class T>
const T& max(const T& a, const T& b, const T& c) {
  return max(a, max(b, c));
}
template <class T>
const T& min(const T& a, const T& b, const T& c) {
  return min(a, min(b, c));
}
long long stoi(string& str) {
  istringstream second(str);
  long long i;
  second >> i;
  return i;
}
string itos(long long i) {
  stringstream second;
  second << i;
  return second.str();
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long poww(long long a, long long b) {
  long long res = 1;
  for (int i = 1; i <= b; i++) res *= a;
  return res;
}
long long sumOfDigs(string s) {
  long long sum = 0;
  for (int i = 0; i < s.length(); i++) sum += s[i] - '0';
  return sum;
}
long long mod = 1000000 + 3;
int program();
using namespace std;
int cnt[2001];
char a[2001][2001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c = a[i][j];
      if (c == 'L' && j - i + 1)
        cnt[j - i + 1]++;
      else if (c == 'R' && j + i - 1 <= m)
        cnt[j + i - 1]++;
      else if (c == 'U' && (i & 1))
        cnt[j]++;
    }
  }
  for (int i = 1; i <= m; i++) cout << cnt[i] << " ";
  cout << endl;
  return 0;
}
