#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long x = power(a, b / 2);
    return (x * x) % M;
  } else
    return (a * power(a, b - 1)) % M;
}
void fun() {
  long long k;
  cin >> k;
  long long n;
  cin >> n;
  map<string, int> m;
  m["white"] = 0;
  m["yellow"] = 1;
  m["green"] = 2;
  m["blue"] = 3;
  m["red"] = 4;
  m["orange"] = 5;
  map<long long, int> vis;
  map<long long, vector<long long>> v;
  set<long long> des;
  map<long long, int> f;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    string s;
    cin >> s;
    int y = m[s];
    vector<long long> cv(6, 0);
    cv[y]++;
    v[x] = cv;
    des.insert(-x);
    f[x]++;
  }
  while (!des.empty()) {
    long long x = -(*des.begin());
    des.erase(des.begin());
    vis[x]++;
    long long lvl = log2(2LL * x) + 1;
    long long nl = lvl;
    if (lvl <= k) {
      vector<long long> cx(6, 0);
      lvl = k - lvl + 1;
      long long curr = pow(2LL, lvl);
      curr -= 2LL;
      if (curr < 0) curr += M;
      curr = power(4, curr);
      cx.assign(6, curr);
      if (vis[2LL * x] == 0) {
        v[2LL * x] = cx;
      }
      if (vis[2LL * x + 1] == 0) v[2LL * x + 1] = cx;
    }
    if (!f[x]) {
      vector<long long> cv(6, 0);
      for (int i = 0; i < 6; i++) {
        int c = i;
        int oc = c;
        if (c % 2 == 0)
          oc++;
        else
          oc--;
        for (int j = 0; j < 6; j++) {
          for (int l = 0; l < 6; l++) {
            if (j != c && j != oc && l != c && l != oc) {
              cv[i] += (v[2LL * x][j] * v[2LL * x + 1][l]) % M;
              cv[i] %= M;
            }
          }
        }
      }
      v[x] = cv;
    } else {
      vector<long long> cv(6, 0);
      for (int i = 0; i < 6; i++) {
        if (v[x][i] == 0 || nl > k) continue;
        int c = i;
        int oc = c;
        if (c % 2 == 0)
          oc++;
        else
          oc--;
        for (int j = 0; j < 6; j++) {
          for (int l = 0; l < 6; l++) {
            if (j != c && j != oc && l != c && l != oc) {
              cv[i] += (v[2LL * x][j] * v[2LL * x + 1][l]) % M;
              cv[i] %= M;
            }
          }
        }
      }
      if (nl <= k) v[x] = cv;
    }
    x /= 2LL;
    if (x != 0) des.insert(-x);
  }
  long long ans = 0;
  for (int i = 0; i < 6; i++) {
    ans += v[1][i];
    ans %= M;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    fun();
    cout << '\n';
  }
}
