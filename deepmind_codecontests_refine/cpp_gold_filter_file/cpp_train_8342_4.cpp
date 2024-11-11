#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int inf = 1000000000;
int n;
vector<int> mas;
unordered_map<int, int> desn;
unordered_map<int, int> kair;
unordered_map<int, vector<pair<int, int> > > cur;
void pridek(int l, int r, int s) {
  if (desn.count(s) == 0) {
    desn[s] = inf;
    kair[s] = -1;
    cur[s] = {};
  }
  if (l > desn[s] || desn[s] == inf) {
    if (desn[s] != inf) cur[s].push_back({kair[s], desn[s]});
    kair[s] = l;
    desn[s] = r;
  }
  if (desn[s] > r) {
    desn[s] = r;
    kair[s] = l;
  }
}
void daryk(int l) {
  int s = 0;
  for (int i = l; i < n; i++) {
    s += mas[i];
    pridek(l, i, s);
  }
}
int main() {
  cin >> n;
  mas.resize(n);
  for (auto &x : mas) cin >> x;
  for (int i = 0; i < n; i++) {
    daryk(i);
  }
  int ans = -inf;
  for (auto x : desn) {
    int s = x.first;
    cur[s].push_back({kair[s], desn[s]});
    if (ans == -inf || cur[s].size() > cur[ans].size()) {
      ans = s;
    }
  }
  cout << cur[ans].size() << "\n";
  for (auto x : cur[ans]) {
    cout << x.first + 1 << " " << x.second + 1 << "\n";
  }
}
