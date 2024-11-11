#include <bits/stdc++.h>
using namespace std;
int n, p[100001], top[100001][2], cnt[100001];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    if (p[i] > top[i - 1][0]) {
      top[i][0] = p[i];
      top[i][1] = top[i - 1][0];
    } else if (p[i] > top[i - 1][1]) {
      top[i][0] = top[i - 1][0];
      top[i][1] = p[i];
    } else {
      top[i][0] = top[i - 1][0];
      top[i][1] = top[i - 1][1];
    }
    if (top[i][1] == p[i]) ++cnt[top[i][0]];
  }
  for (int i = 1; i <= n; ++i)
    if (top[i][0] == i) --cnt[i];
  int best = 1;
  for (int i = 2; i <= n; ++i)
    if (cnt[i] > cnt[best]) best = i;
  cout << best << '\n';
}
