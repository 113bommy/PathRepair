#include <bits/stdc++.h>
using namespace std;
map<long long, bool> tz;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int cnk(long long n, long long k, long long mod) {
  long long result = 1;
  int lal = 0;
  for (int lol = n; lal < k; lal++, lol--) {
    result *= lol;
    result %= mod;
  }
  return result;
}
const long long mod = 1e9 + 7;
vector<long long> graph[100000];
vector<pair<double, long long> > vec;
vector<long long> vec1[1001];
vector<long long> vec2[1001];
long long mas[100001];
vector<long long> nap[4];
bool masi[100000];
long long mas1[100];
long long mas2[100];
string s;
int main() {
  long long a, b, c, d;
  string s;
  cin >> a >> b >> s;
  long long res = 0;
  long long resi = 0;
  long long mini = 1e9, maxi = -1;
  for (long long lol = 0; lol < a / 2; lol++) {
    res += min(abs(s[lol] - s[a - lol - 1]), 26 - abs(s[lol] - s[a - lol - 1]));
    if (s[lol] != s[a - lol - 1]) {
      mini = min(mini, lol);
      maxi = max(maxi, lol);
    }
  }
  if (res == 0) {
    cout << 0;
    return 0;
  }
  b--;
  resi = min(abs(b - mini), abs(b - maxi)) + (maxi - mini);
  mini = a - mini - 1;
  maxi = a - maxi - 1;
  resi = min(resi, min(abs(b - mini), abs(b - maxi)) + (mini - maxi));
  cout << res + resi;
  return 0;
}
