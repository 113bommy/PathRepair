#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 7;
const int INF = 1e9 + 7;
const long long int LINF = 1e18;
const long long int MOD = 1e9 + 7;
using namespace std;
int n, m;
vector<pair<long long int, char> > a, b, bb;
int p[MAXN];
long long int ans;
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    long long int x;
    char c;
    int xx;
    scanf("%d-%c", &xx, &c);
    x = xx;
    if (i > 1 && a.back().second == c) {
      a.back().first += x;
    } else {
      a.push_back(make_pair(x, c));
    }
  }
  scanf("\n");
  for (int i = 1; i <= m; i++) {
    long long int x;
    int xx;
    char c;
    scanf("%d-%c", &xx, &c);
    x = xx;
    if (i > 1 && b.back().second == c) {
      b.back().first += x;
    } else {
      b.push_back(make_pair(x, c));
    }
  }
  if ((int)b.size() == 1) {
    for (auto i : a) {
      if (i.second == b[0].second) {
        ans += max(i.first - b[0].first + 1ll, 0ll);
      }
    }
  } else if ((int)b.size() == 2) {
    for (int i = 0; i + 1 < a.size(); i++) {
      if (a[i].second == b[0].second && a[i].first >= b[0].first) {
        if (a[i + 1].second == b[1].second && a[i + 1].first >= b[1].first) {
          ans++;
        }
      }
    }
  } else {
    for (int i = 1; i + 1 < b.size(); i++) {
      bb.push_back(b[i]);
    }
    int sz = (int)bb.size();
    bb.push_back(make_pair(-1ll, '%'));
    for (auto i : a) {
      bb.push_back(i);
    }
    for (int i = 1; i < bb.size(); i++) {
      int j = p[i - 1];
      while (j > 0 && bb[j] != bb[i]) {
        j = p[j - 1];
      }
      if (bb[j] == bb[i]) {
        j++;
      }
      p[i] = j;
    }
    for (int i = sz + 1; i + 1 < bb.size(); i++) {
      if (p[i] == sz) {
        if (bb[i - 1].second == b[0].second) {
          if (bb[i + sz].second == b.back().second) {
            if (bb[i - 1].first >= b[0].first) {
              if (bb[i + sz].first >= b.back().first) {
                ans++;
              }
            }
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
