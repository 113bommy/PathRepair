#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long mo = 1e9 + 7;
long long sx, sy, ex, ey, dx[6] = {0, 1, 0, -1, 0, 0},
                          dy[6] = {1, 0, -1, 0, 0, 0}, m, n, k,
                          dz[6]{0, 0, 0, 0, -1, 1}, sg;
long long p, no, v, ans, w;
int par[550];
long long gcd(long long a, long long b) { return a ? gcd(b % a, a) : b; }
set<long long> se;
struct node {
  long long u, v, w;
};
vector<node> eg;
long long qu(long long a, long long b, long long m) {
  long long ans = 1;
  while (b) {
    if (b & 1) {
      ans = ans % m * a % m;
    }
    b >>= 1;
    a = a % m * a % m;
  }
  return ans;
}
int su(int n) {
  if (n == 1 || n == 0) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
int fi(int a) {
  if (a == par[a])
    return a;
  else
    return par[a] = fi(par[a]);
}
map<int, int> mp, mp1[3];
map<pair<long long, long long>, int> mp2;
priority_queue<long long, vector<long long>, greater<long long> > que;
vector<long long> ve, ve1;
int cmp1(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
int cmp(node a, node b) { return a.w < b.w; }
int main() {
  int t, p2, p3;
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s, ss, sss;
  long long l, r, n1, u;
  int tot = 1;
  char ch;
  while (cin >> t) {
    while (t--) {
      cin >> n;
      cin >> s;
      sg = 0;
      long long re = 0, ct = s.length();
      for (int i = 1; i <= n; i++) {
        if (ct < n && !sg) {
          no = s[i - 1] - '0';
          ct = i + (ct - i) * no;
          re = s.length();
          for (int j = 0; j < no - 1; j++)
            for (int k = i; k < re; k++) s += s[k];
        } else {
          sg = 1;
          no = s[i - 1] - '0';
          ct = (no * (ct - i + mo) % mo + i) % mo;
        }
      }
      cout << ct << endl;
    }
  }
}
