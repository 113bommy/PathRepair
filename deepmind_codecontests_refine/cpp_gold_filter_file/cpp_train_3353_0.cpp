#include <bits/stdc++.h>
using namespace std;
const int maxn = 300;
int n;
int need[maxn];
int test[maxn];
int have[maxn];
vector<pair<int, int> > edges;
int ct[maxn];
void scan() {
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(3); ++j) {
      int x;
      cin >> x;
      need[i] = need[i] * 2 + x;
    }
  }
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)(3); ++j) {
      int x;
      cin >> x;
      test[i] = test[i] * 2 + x;
    }
    test[i] &= need[i];
  }
}
void solve() {
  memset(have, -1, sizeof have);
  memset(ct, -1, sizeof ct);
  have[7] = 0;
  ct[0] = 1;
  bool done = true;
  while (done) {
    done = false;
    for (int v = 0; v < (int)(n); ++v)
      if (ct[v] == -1) {
        int x = need[v];
        if (have[x] != -1 && (test[v] & x) && have[test[v] & x] == -1) {
          ct[v] = 1;
          have[x & test[v]] = v;
          edges.emplace_back(have[x], v);
          done = true;
          break;
        }
      }
    if (done) continue;
    for (int v = 0; v < (int)(n); ++v)
      if (ct[v] == -1) {
        int x = need[v];
        if (have[test[v] & x] != -1) continue;
        if (!(test[v] & x)) continue;
        for (int y = 0; y < (int)(8); ++y)
          if (!done)
            for (int z = 0; z < (int)(y); ++z)
              if (have[y] != -1 && have[z] != -1 && (y | z) == x) {
                cerr << have[y] << " " << have[z] << "\n";
                ct[v] = 1;
                have[x & test[v]] = v;
                edges.emplace_back(have[y], v);
                edges.emplace_back(have[z], v);
                done = true;
                break;
              }
        if (done) break;
      }
    if (done) continue;
    for (int v = 0; v < (int)(n); ++v)
      if (ct[v] == -1) {
        int x = need[v];
        if (have[x] != -1) continue;
        for (int y = 0; y < (int)(8); ++y)
          if (!done)
            for (int z = 0; z < (int)(y); ++z)
              if (have[y] != -1 && have[z] != -1 && (y | z) == x) {
                ct[v] = 0;
                have[x] = v;
                edges.emplace_back(have[y], v);
                edges.emplace_back(have[z], v);
                done = true;
                break;
              }
        if (done) break;
      }
  }
  for (int v = 0; v < (int)(n); ++v)
    if (ct[v] == -1) {
      if (need[v] == 0) {
        ct[v] = 0;
        continue;
      }
      if (have[need[v]] == -1) {
        cout << "Impossible\n";
        return;
      }
      edges.emplace_back(have[need[v]], v);
      ct[v] = 0;
    }
  cout << "Possible\n";
  for (int i = 0; i < (int)(n); ++i) cout << ct[i] << " \n"[i + 1 == n];
  cout << edges.size() << "\n";
  for (auto kv : edges) {
    cout << kv.first + 1 << " " << kv.second + 1 << "\n";
  }
}
int main() {
  scan();
  solve();
  return 0;
}
