#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
vector<pair<int, int> > seg;
bool st[N];
void query(int x) {
  char s[2];
  for (int i = seg[x].first; i <= seg[x].second; i++) {
    cout << "? " << i << endl;
    cout.flush();
    cin >> s;
    if (s[0] == 'Y') st[i] = true;
  }
}
void solve() {
  int n = seg.size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      query(i);
      query(j);
      cout << "R" << endl;
      cout.flush();
    }
}
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i += (k + 1) / 2) {
    int left = i;
    int right = min(i + (k + 1) / 2 - 1, n);
    seg.push_back({left, right});
  }
  solve();
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (!st[i]) res++;
  cout << "! " << res << endl;
  cout.flush();
  return 0;
}
