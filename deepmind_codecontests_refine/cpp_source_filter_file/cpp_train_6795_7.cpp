#include <bits/stdc++.h>
using namespace std;
const uint64_t SEED =
    chrono::steady_clock::now().time_since_epoch().count() * 1;
mt19937_64 rng(SEED);
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) {
    cin >> i;
    i--;
  }
  vector<int64_t> index_hash(n);
  for (auto &i : index_hash) i = rng();
  vector<queue<int> > pos(n);
  vector<uint64_t> hashes(n);
  map<int64_t, int> how_much_hashes;
  map<int, int> cnt;
  int lbound = 0;
  long long res = 0;
  how_much_hashes[0] = 1;
  for (int i = 0; i < n; i++) {
    pos[v[i]].push(i);
    cnt[v[i]]++;
    int diff = (cnt[v[i]] % 3 == 0 ? -2 : 1);
    hashes[i] = (i > 0 ? hashes[i - 1] : (uint64_t)0) + diff * index_hash[v[i]];
    how_much_hashes[hashes[i]]++;
    if (pos[v[i]].size() == 4) {
      int removedpos = pos[v[i]].front();
      pos[v[i]].pop();
      while (lbound <= removedpos) {
        if (lbound == 0)
          how_much_hashes[0]--;
        else
          how_much_hashes[hashes[lbound]]--;
        lbound++;
      }
    }
    res += how_much_hashes[hashes[i]];
  }
  cout << res - n << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  while (t--) solve();
}
