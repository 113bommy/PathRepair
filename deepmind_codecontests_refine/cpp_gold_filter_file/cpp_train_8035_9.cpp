#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    vector<int> v(n), fir(n, n + 1), lst(n, -1);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      --v[i];
      fir[v[i]] = min(fir[v[i]], i);
      lst[v[i]] = max(lst[v[i]], i);
    }
    vector<int> cur;
    for (int i = 0; i < n; ++i) {
      if (fir[i] != n + 1 && lst[i] != n + 1) {
        cur.push_back(i);
      }
    }
    sort((cur).begin(), (cur).end());
    long long ans = 1, now = 1;
    for (int i = 0; i < cur.size() - 1; ++i) {
      if (lst[cur[i]] < fir[cur[i + 1]] && lst[cur[i]] != -1) {
        ++now;
        ans = max(ans, now);
      } else
        now = 1;
    }
    cout << cur.size() - ans << endl;
  }
}
