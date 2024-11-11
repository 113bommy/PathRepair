#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long OO = (long long)1e18;
const int dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long fast_power(long long base, long long power) {
  if (power == 1) return base;
  if (power % 2 == 0)
    return fast_power((base * base), power / 2);
  else
    return (base * fast_power((base * base), power / 2));
}
void Qalbaz() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(1);
}
int main() {
  Qalbaz();
  map<char, char> mp;
  string str = "AHIMOoTUVvWwXxY";
  mp['b'] = 'd';
  mp['d'] = 'b';
  mp['p'] = 'q';
  mp['q'] = 'p';
  string ss;
  cin >> ss;
  char c1, c2;
  for (int i = 0; i < ss.size() / 2; i++) {
    c1 = ss[i];
    c2 = ss[ss.size() - i - 1];
    if (c1 == c2) {
      if (str.find(c1) == -1) {
        cout << "NIE";
        return 0;
      }
    } else if (mp[c1] != c2 && c1 != c2) {
      cout << "NIE";
      return 0;
    }
  }
  if (ss.size() % 2 == 1) {
    c1 = ss[ss.size() / 2 + 1];
    if (str.find(c1) == -1) {
      cout << "NIE";
      return 0;
    }
  }
  cout << "TAK";
  return 0;
}
