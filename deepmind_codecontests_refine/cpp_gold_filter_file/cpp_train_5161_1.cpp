#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int k, n;
  cin >> k >> n;
  map<string, vector<int> > val;
  map<string, string> rev;
  for (int K = 0; K < k; K++) {
    string s;
    string pal;
    int price;
    cin >> s >> price;
    pal = s;
    reverse(pal.begin(), pal.end());
    rev[s] = pal;
    val[s].push_back(price);
  }
  for (auto& p : val) {
    vector<int>& cur = p.second;
    sort(cur.begin(), cur.end());
  }
  long long ans = 0;
  const int inf = (int)(1e9);
  int minminus = inf;
  for (auto p : rev) {
    if (p.first == p.second) {
      vector<int>& cur = val[p.first];
      while (cur.size() > 1) {
        int x = cur.back();
        cur.pop_back();
        int y = cur.back();
        if (x + y > 0) {
          ans += x + y;
          minminus = min(minminus, y);
          cur.pop_back();
        } else {
          cur.push_back(x);
          break;
        }
      }
    } else {
      vector<int>& cur = val[p.first];
      vector<int>& that = val[p.second];
      while (cur.size() > 0 && that.size() > 0) {
        int x = cur.back();
        int y = that.back();
        if (x + y > 0) {
          ans += x + y;
          cur.pop_back();
          that.pop_back();
        } else {
          break;
        }
      }
    }
  }
  int mxpal = -inf;
  for (auto p : rev) {
    if (p.first == p.second) {
      vector<int>& cur = val[p.first];
      if (cur.size() > 0) {
        mxpal = max(mxpal, cur.back());
      }
    }
  }
  ans = max(ans, max(ans + mxpal, ans - minminus));
  ans = max(0ll, ans);
  cout << ans << endl;
}
