#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 1;
const long long M = 1e9 + 7;
const long long H = 1e5 + 7;
const long long B = 1e4 + 7;
const long long A = 1e6 + 7;
set<long long> o;
map<long long, long long> mp, pm;
map<char, long long> hs;
vector<long long> v, vc, ve, vv;
vector<char> vd;
deque<long long> p, pe;
deque<string> ts, ss, stoi, rs;
deque<double> sd, ds;
string s, g, w, h, s1;
double l;
char z, u = 'a';
bool re, rt;
deque<long long> e;
map<pair<long long, long long>, long long> aw, wa;
long long cnt, ans, TT, n, a, b, c, q, m, t, d, temp, mn, mx, rem, sum, tt;
long long used[N];
long long arr[10001];
int main() {
  ios_base::sync_with_stdio(0);
  srand(time(NULL));
  cin >> c;
  for (long long i = 0; i < c; i++) {
    cin >> a >> b >> n >> m;
    cnt = max(n, a - 1 - n) * b;
    ans = max(m, b - 1 - m) * a;
    cout << max(cnt, ans) << endl;
    cnt = ans = 0;
  }
}
