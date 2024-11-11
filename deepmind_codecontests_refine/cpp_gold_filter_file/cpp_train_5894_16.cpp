#include <bits/stdc++.h>
#pragma GCC optimize("O3")
const double PI = acos(-1.0);
using namespace std;
const int N = 800007, M = 1000000;
const double EPS = 1e-9;
int n, m, a[N];
int b[N][2], e, nxt[N][2], val[N], lef[N];
void add(vector<int> &v, int i, int cur) {
  if (i == 20) {
    lef[cur] = 1;
    return;
  }
  if (v[i] == 0) {
    if (b[cur][0] == -1) {
      b[cur][0] = 0;
      nxt[cur][0] = ++e;
      val[e] = 0;
    }
    add(v, i + 1, nxt[cur][0]);
  } else {
    if (b[cur][1] == -1) {
      b[cur][1] = 1;
      nxt[cur][1] = ++e;
      val[e] = 1;
    }
    add(v, i + 1, nxt[cur][1]);
  }
  lef[cur] = ((b[cur][0] != -1) ? lef[nxt[cur][0]] : 0) +
             ((b[cur][1] != -1) ? lef[nxt[cur][1]] : 0);
}
void get(vector<int> &v, int i, int cur, int &ans) {
  if (i == 20) return;
  if (v[i] == 0) {
    if (b[cur][0] == -1)
      for (int j = i; j <= 19; j++) ans *= 2;
    else if (lef[nxt[cur][0]] < (1 << (19 - i)))
      get(v, i + 1, nxt[cur][0], ans = ans * 2);
    else {
      if (b[cur][1] == -1) {
        ans = ans * 2 + 1;
        for (int j = i + 1; j <= 19; j++) ans *= 2;
      } else
        get(v, i + 1, nxt[cur][1], ans = ans * 2 + 1);
    }
  } else {
    if (b[cur][1] == -1)
      for (int j = i; j <= 19; j++) ans *= 2;
    else if (lef[nxt[cur][1]] < (1 << (19 - i)))
      get(v, i + 1, nxt[cur][1], ans = ans * 2);
    else {
      if (b[cur][0] == -1) {
        ans = ans * 2 + 1;
        for (int j = i + 1; j <= 19; j++) ans *= 2;
      } else
        get(v, i + 1, nxt[cur][0], ans = ans * 2 + 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n >> m;
  memset(b, -1, sizeof b);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    vector<int> v;
    int g = a[i];
    while (g) {
      v.push_back(g % 2);
      g /= 2;
    }
    while (v.size() < 20) v.push_back(0);
    reverse(v.begin(), v.end());
    add(v, 0, 0);
  }
  int c = 0, x, p;
  while (m--) {
    cin >> x;
    c ^= x;
    vector<int> v;
    int g = c;
    while (g) {
      v.push_back(g % 2);
      g /= 2;
    }
    while (v.size() < 20) v.push_back(0);
    reverse(v.begin(), v.end());
    int ans = 0;
    get(v, 0, 0, ans);
    cout << min(ans, 300000) << endl;
    p = ans;
  }
  return 0;
}
