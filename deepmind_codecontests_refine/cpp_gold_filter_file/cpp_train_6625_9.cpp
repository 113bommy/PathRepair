#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj(26);
int solve(int l, int r, int pos, int val) {
  if (l <= r) {
    int mid = l + (r - l) / 2, mid_val = adj[pos][mid];
    if (mid_val > val && (mid == l || adj[pos][mid - 1] <= val)) return mid;
    if (mid_val <= val) return solve(mid + 1, r, pos, val);
    return solve(l, mid - 1, pos, val);
  }
  return -1;
}
int main() {
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) adj[a[i] - 'a'].push_back(i);
  long long ret = 1, last = -1;
  for (int i = 0; i < b.size(); i++) {
    if (adj[b[i] - 'a'].size() == 0) {
      ret = -1;
      break;
    }
    int val = solve(0, adj[b[i] - 'a'].size() - 1, b[i] - 'a', last);
    int new_val = adj[b[i] - 'a'][0];
    if (val != -1) new_val = adj[b[i] - 'a'][val];
    if (last >= new_val) {
      ret++;
      last = adj[b[i] - 'a'][0];
    } else {
      last = new_val;
    }
  }
  cout << ret << "\n";
}
