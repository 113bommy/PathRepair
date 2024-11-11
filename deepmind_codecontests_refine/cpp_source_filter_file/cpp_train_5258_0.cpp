#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
long long fastExpo(long long aa, long long bb) {
  long long res = 1;
  while (bb > 0) {
    if (bb & 1) {
      res = (res * aa) % N;
    }
    aa = (aa * aa) % N;
    bb = bb >> 1;
  }
  return res;
}
long long mmi(long long nn) { return fastExpo(nn, N - 2); }
const long long ramramaramnamshamnam = 1e6 + 1;
long long facti[ramramaramnamshamnam];
void facto() {
  facti[0] = 1;
  for (long long i = 1; i < 1e6 + 1; i++) {
    facti[i] = (facti[i - 1] * i) % N;
  }
}
vector<long long> adj[100001];
long long vis[100001];
void dfs(long long node) {
  vis[node] = 1;
  for (auto child : adj[node]) {
    if (vis[child] == 0) dfs(child);
  }
}
void solve() {
  long long n, t;
  cin >> n >> t;
  string s1;
  string s2;
  cin >> s1 >> s2;
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (s1[i] == s2[i]) {
      cnt++;
    }
  }
  vector<char> v(n, '0');
  long long temp = 2 * (n - t);
  long long a = 2 * cnt;
  long long b = n - cnt;
  if (temp > (a + b))
    cout << "-1"
         << "\n";
  else {
    for (long long i = 0; i < n; i++) {
      if (temp == 0) break;
      if (s1[i] == s2[i]) {
        temp = temp - 2;
        v[i] = s1[i];
      }
    }
    long long flag = 0;
    for (long long i = 0; i < n; i++) {
      if (s1[i] != s2[i] && temp > 0) {
        temp--;
        if (flag == 0) {
          v[i] = s1[i];
          flag = 1;
        } else {
          v[i] = s2[i];
          flag = 1;
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      if (v[i] == '0') {
        for (char c = 'a'; c <= 'z'; c++) {
          if (c != s1[i] && c != s2[i]) {
            v[i] = c;
            break;
          }
        }
      }
    }
    for (auto first : v) cout << first;
  }
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cout << fixed << setprecision(15);
  long long T = 1;
  while (T--) solve();
}
