#include <bits/stdc++.h>
using namespace std;
void bad() {
  cout << "No\n";
  exit(0);
}
const int N = 1e6;
int n;
long long b[N];
bool isbit(long long mask, int bit) { return ((1ll << bit) & mask) != 0; }
int sz[N];
vector<vector<int> > trie[60];
long long get(int st, long long xr) {
  int vr = 0;
  long long res = 0;
  for (int j = 59; j >= 0; j--) {
    int bt = isbit(xr, j);
    if (trie[st][trie[st][vr][bt]][2] != 0) {
      res += (1ll << j) * bt;
      trie[st][trie[st][vr][bt]][2]--;
      vr = trie[st][vr][bt];
    } else {
      bt = 1 - bt;
      res += (1ll << j) * bt;
      trie[st][trie[st][vr][bt]][2]--;
      vr = trie[st][vr][bt];
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  vector<int> nill = {0, 0, 0};
  for (int i = 0; i < 60; i++) trie[i].push_back(nill);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    int vr = 0, st = 0;
    for (int j = 59; j >= 0; j--)
      if (isbit(b[i], j)) {
        st = j;
        break;
      }
    sz[st]++;
    for (int j = 59; j >= 0; j--) {
      int bt = isbit(b[i], j);
      if (trie[st][vr][bt] == 0) {
        trie[st].push_back(nill);
        trie[st][vr][bt] = trie[st].size() - 1;
      }
      vr = trie[st][vr][bt];
      trie[st][vr][2]++;
    }
  }
  long long xr = 0;
  vector<long long> ans;
  for (int i = 1; i <= n; i++) {
    int found = 0;
    for (int j = 0; j < 60; j++)
      if (!isbit(xr, j) && sz[j] > 0) {
        found = 1;
        sz[j]--;
        long long q = get(j, xr);
        ans.push_back(q);
        xr ^= q;
        break;
      }
    if (!found) bad();
  }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) cout << ans[i - 1] << " ";
  cout << "\n";
  return 0;
}
