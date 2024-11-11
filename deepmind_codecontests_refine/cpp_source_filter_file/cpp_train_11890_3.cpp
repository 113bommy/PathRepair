#include <bits/stdc++.h>
using namespace std;
char ask(int u, int v) {
  cout << "? " << u << " " << v << endl;
  char ans;
  cin >> ans;
  fflush(stdout);
  return ans;
}
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > cur;
  for (int i = 1; i <= n; ++i) {
    cur.push_back({i, n + i});
  }
  for (int i = 0; i < n; ++i) {
    char c = ask(cur[i].first, cur[i].second);
    if (c == '>') swap(cur[i].first, cur[i].second);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      char c = ask(cur[i].first, cur[j].first);
      if (c == '<') swap(cur[i], cur[j]);
    }
  }
  char c = ask(cur[1].second, cur[2].second);
  if (c == '<') swap(cur[1], cur[2]);
  vector<int> a;
  for (int i = 0; i < n; ++i) {
    a.push_back(cur[i].first);
    if (i > 1) a.push_back(cur[i].second);
  }
  for (int i = 0; i < a.size(); ++i) {
    for (int j = i + 1; j < a.size(); ++j) {
      int c = ask(a[i], a[j]);
      if (c == '<') swap(a[i], a[j]);
    }
  }
  cout << "!" << endl;
}
int main() {
  int nT;
  cin >> nT;
  while (nT--) solve();
}
