#include <bits/stdc++.h>
using namespace std;
int t, n, x, y, m;
vector<int> colcnt, corcnt, guess, ans, derange;
vector<vector<int>> pos;
pair<int, int> temp, temp2;
struct cmp {
  bool operator()(pair<int, int> x, pair<int, int> y) const {
    return x.second == y.second ? x.first < y.first : x.second > y.second;
  }
};
set<pair<int, int>, cmp> codes;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> x >> y;
    colcnt = corcnt = vector<int>(n + 2);
    pos = vector<vector<int>>(n + 2, vector<int>());
    guess = ans = vector<int>(n, -1);
    codes.clear();
    derange.clear();
    int c, rc = -1;
    for (int i = 0; i < n; i++) {
      cin >> c;
      colcnt[c]++;
      pos[c].push_back(i);
      guess[i] = c;
    }
    for (int i = 1; i <= n + 1; i++) {
      if (colcnt[i] == 0) {
        rc = i;
      } else {
        codes.insert({i, colcnt[i]});
      }
    }
    for (int i = 0; i < x; i++) {
      temp = *codes.begin();
      codes.erase(temp);
      corcnt[temp.first]++;
      colcnt[temp.first]--;
      temp.second--;
      if (temp.second > 0) codes.insert(temp);
    }
    int half = y - x, rem = n - x, nc = 0;
    for (int i = 1; i <= n + 1; i++) {
      int tneed = min(colcnt[i], half - (rem - colcnt[i]));
      if (tneed + colcnt[i] > rem) nc++;
    }
    if (nc > 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        int c = guess[i];
        if (corcnt[c] > 0) {
          ans[i] = c;
          corcnt[c]--;
        }
      }
      int idx;
      for (int i = 1; i <= n + 1; i++) {
        int used = 0, s = min(colcnt[i], rem - colcnt[i]);
        for (int j = 0; j < pos[i].size(); j++) {
          idx = pos[i][j];
          if (ans[idx] == -1) {
            derange.push_back(idx);
            used++;
            if (used >= s) break;
          }
        }
      }
      int dsize = derange.size();
      int move = dsize / 2;
      for (int i = 0; i < dsize; i++) {
        if (i < half)
          ans[derange[i]] = guess[derange[(i + move) % dsize]];
        else
          ans[derange[i]] = rc;
      }
      for (int i = 0; i < n; i++)
        if (ans[i] == -1) ans[i] = rc;
      for (int i = 0; i < n; i++) cout << ans[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
