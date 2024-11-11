#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 10;
set<int> s;
int a[MAXN], tedad = 0;
map<int, int> ind, cnt;
vector<int> v;
bool mark[MAXN];
void change(int id, int p) {
  auto itr = s.lower_bound(id);
  int b = -1e9, f = -1e9;
  if (itr != s.begin()) {
    itr--;
    int num = a[id] - a[*itr];
    b = a[*itr];
    cnt[num] += p;
    if (p == -1 and cnt[num] == 0) tedad--;
    if (p == +1 and cnt[num] == 1) tedad++;
    itr++;
  }
  if (p == -1) itr++;
  if (itr != s.end()) {
    int num = a[*itr] - a[id];
    f = a[*itr];
    cnt[num] += p;
    if (p == -1 and cnt[num] == 0) tedad--;
    if (p == +1 and cnt[num] == 1) tedad++;
  }
  if (b != -1e9 and f != -1e9) {
    cnt[f - b] += -p;
    if (p == +1 and cnt[f - b] == 0) tedad--;
    if (p == -1 and cnt[f - b] == 1) tedad++;
  }
  if (p == -1)
    s.erase(id);
  else
    s.insert(id);
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], ind[a[i]] = i;
  if (n == 2) {
    cout << a[0] << endl << a[1] << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) change(i, 1);
  for (int i = 1; i < n; i++) {
    int dis = a[i] - a[0];
    int id = 0;
    while (id < n and tedad > 1) {
      v.push_back(id);
      change(id, -1);
      int id2 = ind[a[id] + dis];
      if (id2 == 0 or id2 < id) break;
      id = id2;
    }
    if (tedad == 1) {
      if (v.size() == 0) v.push_back(0);
      if (int(v.size()) == n) v.pop_back();
      for (auto u : v) mark[u] = true;
      for (auto u : v) cout << a[u] << ' ';
      cout << endl;
      for (int j = 0; j < n; j++)
        if (mark[j] == false) cout << a[j] << ' ';
      cout << endl;
      return 0;
    } else {
      for (auto u : v) change(u, 1);
      v.clear();
    }
  }
  cout << "No solution" << endl;
  return 0;
}
