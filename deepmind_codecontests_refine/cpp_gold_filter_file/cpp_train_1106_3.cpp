#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, siz = 1e6 + 5;
int t, n, m, id1, id2, k, a[siz], have[siz];
string inp[3000], god;
bool ok() {
  for (int i = 1; i <= k; i++) {
    int probs = 0;
    int p1 = -1, p2 = -1;
    for (int j = 0; j < n; j++) {
      if (god[j] != inp[i][j]) {
        if (probs == 0) p1 = j;
        if (probs == 1) p2 = j;
        probs++;
      }
    }
    if (probs != 0 and probs != 2) return false;
    if (probs == 0) {
      bool ok = 0;
      for (int j = 0; j < n; j++) {
        have[inp[i][j]]++;
        if (have[inp[i][j]] > 1) ok = 1;
      }
      for (char c = 'a'; c <= 'z'; c++) have[c] = 0;
      if (!ok) return false;
    }
    if (probs == 2) {
      if ((god[p1] != inp[i][p2]) or (god[p2] != inp[i][p1])) return false;
    }
  }
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> k >> n;
  map<pair<int, int>, bool> mp;
  for (int i = 1; i <= k; i++) {
    cin >> inp[i];
  }
  id1 = -1, id2 = -1;
  for (int i = 1; i < k; i++) {
    if (id1 != -1) break;
    for (int j = i + 1; j <= k; j++) {
      if (inp[i] != inp[j]) {
        id1 = i, id2 = j;
        break;
      }
    }
  }
  if (id1 == -1) {
    swap(inp[1][0], inp[1][1]);
    cout << inp[1] << endl;
    return 0;
  }
  vector<int> v;
  for (int i = 0; i < n; i++)
    if (inp[id1][i] != inp[id2][i]) v.push_back(i);
  if (v.size() > 4) return cout << -1 << endl, 0;
  for (int z = 0; z < 2; z++) {
    for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < n; j++) {
        swap(inp[id1][v[i]], inp[id1][j]);
        god = inp[id1];
        swap(inp[id1][v[i]], inp[id1][j]);
        if (ok()) {
          cout << god << endl;
          return 0;
        }
      }
    }
    id1 = id2;
  }
  cout << -1 << endl;
}
