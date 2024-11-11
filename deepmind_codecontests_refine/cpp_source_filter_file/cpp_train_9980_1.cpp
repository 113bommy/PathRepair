#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 1e5 + 7;
const int C = (int) 1e18;
int h, w, n;
int mnf, mns;
int f[N];
int s[N];
vector<pair<int, int>> a[N];
vector<pair<int, int>> b[N];

void dfsa(int i);
void dfsb(int i);

void dfsa(int i) {
  mnf = min(mnf, f[i]);
  for (auto &it : a[i]) {
    int j = it.first;
    int val = it.second;
    if (s[j] == C) {
      s[j] = val - f[i];
      dfsb(j);
    } else {
      if (s[j] != val - f[i]) {
        cout << "No\n";
        exit(0);
      }
    }
  }
}

void dfsb(int i) {
  mns = min(mns, s[i]);
  for (auto &it : b[i]) {
    int j = it.first;
    int val = it.second;
    if (f[j] == C) {
      f[j] = val - s[i];
      dfsa(j);
    } else {
      if (f[j] != val - s[i]) {
        cout << "No\n";
        exit(0);
      }
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> h >> w >> n;
  for (int i = 1; i <= h; i++) {
    f[i] = C;
  }
  for (int i = 1; i <= w; i++) {
    s[i] = C;
  }
  for (int k = 1; k <= n; k++) {
    int i, j, x;
    cin >> i >> j >> x;
    a[i].push_back({j, x});
    b[j].push_back({i, x});
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] == C) {
      mnf = (int) 1e18, mns = (int) 1e18;
      f[i] = 0;
      dfsa(i);
      if (mnf + mns < 0) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
}
