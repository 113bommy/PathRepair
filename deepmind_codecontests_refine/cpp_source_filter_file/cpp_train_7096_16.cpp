#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int val[maxn];
vector<pair<int, int> > interv;
int ans[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    if (t == 1) {
      for (int j = l; j < r; j++) {
        val[j] = 1;
      }
    } else {
      interv.push_back(pair<int, int>(l, r));
    }
  }
  ans[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (val[i - 1] == 1)
      ans[i] = ans[i - 1] + 1;
    else
      ans[i] = ans[i - 1] - 1;
  }
  for (pair<int, int> i : interv) {
    int prev = ans[i.first];
    bool good = false;
    for (int j = i.first + 1; j <= i.second; j++) {
      if (ans[j] < prev) {
        good = true;
        break;
      }
      prev = ans[j];
    }
    if (!good) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}
