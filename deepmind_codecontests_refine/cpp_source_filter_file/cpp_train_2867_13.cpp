#include <bits/stdc++.h>
using namespace std;
int v[20000];
vector<int> g;
int main() {
  int n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  v[a] = 1;
  v[b] = 1;
  v[c] = 1;
  v[d] = 1;
  int cur = 1;
  if (n <= 4) {
    cout << "-1";
    return 0;
  }
  if (n == 5) {
    if (k < 6) {
      cout << "-1";
      return 0;
    }
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << a << " ";
        g.push_back(a);
        continue;
      }
      if (i == n - 1) {
        cout << b << " ";
        g.push_back(b);
        continue;
      }
      if (i == 1) {
        cout << c << " ";
        g.push_back(c);
        continue;
      }
      if (i == 3) {
        cout << d << " ";
        g.push_back(d);
        continue;
      }
      while (v[cur] != 0) cur++;
      g.push_back(cur);
      cout << cur << " ";
    }
    cout << "\n";
    cout << c << " " << g[0] << " " << g[4] << " " << g[2] << " " << d;
    return 0;
  }
  if (k < n + 1) {
    cout << "-1";
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << a << " ";
      g.push_back(a);
      continue;
    }
    if (i == 1) {
      cout << c << " ";
      g.push_back(c);
      continue;
    }
    if (i == 4) {
      cout << d << " ";
      g.push_back(d);
      continue;
    }
    if (i == n - 1) {
      cout << b << " ";
      g.push_back(b);
      continue;
    }
    while (v[cur] != 0) cur++;
    g.push_back(cur);
    cout << cur << " ";
    cur++;
  }
  cout << "\n";
  cout << g[1] << " " << g[0] << " " << g[3] << " " << g[2] << " ";
  for (int i = n - 1; i >= 4; i--) {
    cout << g[i] << " ";
  }
  return 0;
}
