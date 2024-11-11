#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
vector<bool> isPrime(1000005 + 1, true);
string tos(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
void seive() {
  isPrime[0] = 0, isPrime[1] = 0;
  for (long long i = 2; i * i <= 1000005; i++)
    if (isPrime[i])
      for (long long j = i * i; j <= 1000005; j += i) isPrime[j] = 0;
}
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
const int val = 111905;
long long mod = 1000003;
int n;
string s, res, tmp1, tmp2;
bool at;
int main() {
  ios::sync_with_stdio(false);
  cin >> s;
  int sz = s.size();
  for (int i = 0; i < sz;) {
    tmp1 = s.substr(i, 2);
    tmp2 = s.substr(i, 3);
    if (i != 0 && (i != sz - 2) && !at && tmp1 == "at") {
      res += "@";
      i += 2;
      at = 1;
    } else if (i != 0 && (i != sz - 3) && tmp2 == "dot") {
      res += ".";
      i += 3;
    } else {
      res += s[i];
      i++;
    }
  }
  cout << res << "\n";
  return 0;
}
