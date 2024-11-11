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
long long mas[100][100];
vector<long long> nap[4];
bool masi[100000];
long long mas1[100];
long long mas2[100];
string s;
int main() {
  long long a, b, c, d;
  long long k = 0;
  double p;
  cin >> a >> b >> c;
  for (long long lol = 0; lol < a; lol++) {
    cin >> k;
    cout << (k * b) % c << " ";
  }
  return 0;
}
