#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#pragma GCC optimize("Ofast")
using namespace std;
std::vector<long long> adj[10000];
bool visited[10000];
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test = 1;
  while (test--) {
    long long n;
    cin >> n;
    long long a[n];
    map<long long, long long> mm;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mm[a[i]]++;
    }
    long long x = 0;
    for (auto xx : mm) x = max(x, xx.second);
    if (x == 1)
      cout << 1;
    else {
      cout << x;
    }
  }
}
