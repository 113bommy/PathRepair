#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> segtree;
vector<int> a;
vector<stack<int>> ids;
vector<int> b;
string answer;
int segtree_size;
void In() {
  cin >> n;
  a.resize(n);
  ids.resize(n + 1);
  b.resize(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
}
void InitSegtree() {
  segtree_size = 1;
  while (segtree_size < n + 1) segtree_size *= 2;
  segtree_size *= 2;
  segtree.resize(segtree_size);
  for (int i = 0; i < n; i++) segtree[i + segtree_size / 2] = a[i];
  for (int i = segtree_size / 2 - 1; i > 0; i--)
    segtree[i] = max(segtree[i * 2], segtree[i * 2 + 1]);
}
void UpdateSegtree(int pos, int value) {
  for (segtree[pos += segtree_size / 2] = value; pos > 1; pos /= 2)
    segtree[pos / 2] = max(segtree[pos], segtree[pos ^ 1]);
}
int QuerySegtree(int start, int finish) {
  int ans = INT_MIN;
  for (start += segtree_size / 2, finish += segtree_size / 2; start < finish;
       start /= 2, finish /= 2) {
    if (start % 2 == 1) ans = max(ans, segtree[start++]);
    if (finish % 2 == 0) ans = max(ans, segtree[finish--]);
  }
  return max(ans, segtree[start]);
}
void Solve() {
  InitSegtree();
  answer = "NO";
  for (int i = 0; i < n; i++) ids[a[i]].push(i);
  for (int i = n - 1; i >= 0; i--) {
    if (ids[b[i]].empty()) return;
    int a_idx = ids[b[i]].top();
    ids[b[i]].pop();
    if (QuerySegtree(a_idx + 1, n) > b[i]) return;
    UpdateSegtree(a_idx, 0);
  }
  answer = "YES";
}
void Out() {
  cout << answer << endl;
  segtree.clear();
  a.clear();
  ids.clear();
  b.clear();
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    In();
    Solve();
    Out();
  }
  return 0;
}
