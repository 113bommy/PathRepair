#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > q;
void solve(int k, int start) {
  if (k == 1)
    q.push_back({start, start + 1});
  else {
    solve(k - 1, start);
    solve(k - 1, start + (1 << (k - 1)));
    for (int i = 0; i < (1 << (k - 1)); ++i) {
      q.push_back({start + i, start + i + (1 << (k - 1))});
    }
  }
}
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1 1";
    return 0;
  }
  int maxk = log2(n);
  solve(maxk, 1);
  solve(maxk, n - (1 << maxk) + 1);
  cout << q.size() << "\n";
  for (auto it : q) cout << it.first << " " << it.second << "\n";
}
