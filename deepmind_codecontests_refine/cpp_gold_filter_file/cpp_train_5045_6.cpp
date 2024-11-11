#include <bits/stdc++.h>
using namespace std;
pair<int, int> c[5010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> c[i].first >> c[i].second;
  sort(c + 1, c + n + 1);
  long long kq = 0;
  for (int i = 1; i <= n; i++) {
    if (c[i].second >= kq)
      kq = c[i].second;
    else
      kq = c[i].first;
  }
  cout << kq;
}
