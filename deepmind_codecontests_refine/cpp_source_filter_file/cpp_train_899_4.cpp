#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;
pair<int, int> p[10100];
vector<pair<int, int> > ans;
set<pair<int, int> > sans;
void solve(int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  solve(l, mid);
  solve(mid + 1, r);
  for (int i = (l); i < (r + 1); i++) {
    ans.push_back({p[mid].second, p[i].second});
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n;
  cin >> n;
  for (int i = (0); i < (n); i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n);
  solve(0, n - 1);
  for (int i = (0); i < (ans.size()); i++) {
    sans.insert(ans[i]);
  }
  for (int i = (0); i < (n); i++) {
    sans.insert(p[i]);
  }
  cout << sans.size() << endl;
  while (!sans.empty()) {
    pair<int, int> pnt = *sans.begin();
    cout << pnt.first << ' ' << pnt.second << endl;
    sans.erase(pnt);
  }
  return 0;
}
