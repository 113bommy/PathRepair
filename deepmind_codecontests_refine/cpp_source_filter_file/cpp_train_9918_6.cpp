#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int maxn = 4e5 + 5;
vector<int> g[1000005];
vector<int> v[500005];
int c[1000005];
void dfs(int now) {
  for (auto &i : g[now]) {
    if (~c[i]) continue;
    c[i] = c[now] ^ 1;
    dfs(i);
  }
}
void go() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "First" << endl;
    for (int i = 1; i < 2 * n + 1; i++) {
      int x = i % (n);
      if (!x) {
        cout << n << ' ';
      } else {
        cout << x << ' ';
      }
    }
    cout << endl;
    cin >> n;
  } else {
    cout << "Second" << endl;
    for (int i = 1; i < n * 2 + 1; i++) {
      int x;
      cin >> x;
      v[x].push_back(i);
      c[i] = -1;
    }
    for (int i = 1; i < n + 1; i++) {
      g[v[i][0]].push_back(v[i][1]);
      g[v[i][1]].push_back(v[i][0]);
      g[i].push_back(i + n);
      g[i + n].push_back(i);
    }
    for (int i = 1; i < n + 1; i++) {
      if (c[i] == -1) {
        c[i] = 0;
        dfs(i);
      }
    }
    int pick = 0;
    long long sum = 0;
    for (int i = 1; i < n * 2 + 1; i++) {
      if (c[i] == pick) {
        sum += i;
      }
    }
    if (sum % (n * 2)) {
      pick ^= 1;
    }
    for (int i = 1; i < n + 1; i++) {
      if (c[i] == pick) {
        cout << i << ' ';
      }
    }
    cout << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int c = 0;
  int t;
  if (!c) {
    t = 1;
  } else {
    cin >> t;
  }
  while (t--) {
    go();
  }
}
