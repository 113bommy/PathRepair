#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 1;
int n, c;
vector<vector<int>> w;
vector<int> sum;
void answer(int ans) {
  cout << ans << '\n';
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> c;
  w.resize(n);
  sum.resize(c + 1);
  int x, a;
  for (int i = 0; i < n; i++) {
    cin >> x;
    for (int j = 0; j < x; j++) {
      cin >> a;
      w[i].emplace_back(a);
    }
  }
  for (int i = 0; i < n - 1; i++) {
    int j = 0;
    int sz = min(w[i].size(), w[i + 1].size());
    for (; j < sz; j++) {
      if (w[i][j] != w[i + 1][j]) break;
    }
    if (j < sz) {
      int a = w[i][j];
      int b = w[i + 1][j];
      if (a < b) {
        sum[0]++;
        sum[c - b + 1]--;
        sum[c - a + 1]++;
        sum[c]--;
      } else {
        sum[c - a + 1]++;
        sum[c - b + 1]--;
      }
    } else {
      if (w[i + 1].size() >= sz) {
        sum[0]++;
        sum[c]--;
      } else
        answer(-1);
    }
  }
  for (int i = 0; i < c; i++) {
    if (sum[i] == (n - 1)) answer(i);
    sum[i + 1] += sum[i];
  }
  answer(-1);
  return 0;
}
