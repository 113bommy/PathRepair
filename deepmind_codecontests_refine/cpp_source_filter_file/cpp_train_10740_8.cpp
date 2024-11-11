#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const long long LINF = 1LL * INF * INF;
const long double PI = acos(-1.);
const double EPS = 1e-6;
long long mod = INF + 7;
const int maxn = 100010;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int b, w;
    cin >> b >> w;
    if (b >= w) {
      vector<pair<int, int> > ans;
      for (int i = 0; i < 2 * w; ++i) ans.push_back(make_pair(3, i + 1));
      b -= w;
      if (b) {
        ans.push_back(make_pair(3, 2 * w + 1));
        b--;
      }
      if (b > 2 * w) {
        cout << "NO" << endl;
        continue;
      }
      int cnt = 2;
      while (b) {
        if (b > 1) {
          ans.push_back(make_pair(2, cnt));
          ans.push_back(make_pair(4, cnt));
          b -= 2;
          cnt += 2;
        } else {
          ans.push_back(make_pair(4, cnt));
          b -= 1;
        }
      }
      cout << "YES" << endl;
      for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
      }
    } else {
      swap(b, w);
      vector<pair<int, int> > ans;
      for (int i = 0; i < 2 * w; ++i) ans.push_back(make_pair(2, i + 1));
      b -= w;
      if (b) {
        ans.push_back(make_pair(2, 2 * w + 1));
        b--;
      }
      if (b > 2 * w) {
        cout << "NO" << endl;
        continue;
      }
      int cnt = 2;
      while (b) {
        if (b > 1) {
          ans.push_back(make_pair(1, cnt));
          ans.push_back(make_pair(3, cnt));
          b -= 2;
          cnt += 2;
        } else {
          ans.push_back(make_pair(3, cnt));
          b -= 1;
        }
      }
      cout << "YES" << endl;
      for (int i = 0; i < (int)ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
      }
    }
  }
  return 0;
}
