#include <bits/stdc++.h>
using namespace std;
void fastcode() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
int dx_r[] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy_c[] = {0, 1, 0, -1, -1, 1, 1, -1};
int main() {
  fastcode();
  string s, y = "aeiouyAEIOUY";
  getline(cin, s);
  int i = s.size() - 2;
  while (s[i] == ' ') {
    i--;
  }
  cout << (y.find(s[i]) != -1 ? "YES" : "NO");
  return 0;
}
