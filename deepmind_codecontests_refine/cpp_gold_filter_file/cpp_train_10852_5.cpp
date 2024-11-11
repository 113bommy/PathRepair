#include <bits/stdc++.h>
using namespace std;
const int N = 403600;
vector<int> bin[N];
int n, s, first, a[N];
int pt[N], q[N];
vector<pair<int, int> > ans;
int main() {
  cin >> n >> s;
  for (int i = (0); i < (int)(n); i++) {
    cin >> first;
    bin[first].push_back(i);
  }
  memset(pt, -1, sizeof(pt));
  int m = 0;
  for (int i = N - 1; i >= 0; i--) {
    for (int j = (0); j < (int)(bin[i].size()); j++) {
      a[m] = i;
      q[m++] = bin[i][j];
    }
    pt[i] = m - 1;
  }
  int cur = N - 1;
  for (int i = (0); i < (int)(n); i++) {
    cur = a[i];
    int bdd = i, last = pt[cur];
    while (a[i]--) {
      bool up = 0;
      if (pt[cur] <= bdd) bdd = last;
      while (cur > 0 && pt[cur] <= bdd) --cur, up = 1;
      if (up) {
        bdd = last;
        last = pt[cur];
      }
      if (cur == 0) {
        break;
      }
      ans.push_back(pair<int, int>(q[i] + 1, q[pt[cur]] + 1));
      a[pt[cur]]--;
      pt[cur]--;
    }
  }
  if (ans.size() * 2 == s) {
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (int i = (0); i < (int)(ans.size()); i++)
      cout << ans[i].first << " " << ans[i].second << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
