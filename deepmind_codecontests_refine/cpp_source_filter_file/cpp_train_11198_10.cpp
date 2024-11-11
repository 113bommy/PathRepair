#include <bits/stdc++.h>
using namespace std;
int n, m;
const int maxn = 100100;
pair<int, int> p[maxn];
int mins = maxn;
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    mins = min(mins, r - l);
  }
  int cnt = 0;
  cout << mins << endl;
  for (int i = 0; i < n; i++) {
    cout << cnt << " ";
    if (cnt == mins)
      cnt = 0;
    else
      cnt++;
  }
  cout << endl;
  return 0;
}
