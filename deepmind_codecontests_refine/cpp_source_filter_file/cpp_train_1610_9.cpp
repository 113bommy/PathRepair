#include <bits/stdc++.h>
using namespace std;
bool vis[100005];
vector<pair<int, int> > res;
vector<int> vec[100005];
vector<int> rem;
bool done[100005];
int n;
int main() {
  cin >> n;
  if (n <= 3) {
    puts("0");
  } else {
    int m = sqrt(100005 + 0.5);
    for (int i = 2; i <= m; i++) {
      if (vis[i]) continue;
      for (int j = i * i; j < 100005; j += i) {
        vis[j] = 1;
      }
    }
    for (int i = 3; i <= n; i++) {
      if (!vis[i]) {
        for (int j = i; j <= n; j += i) {
          if (!done[j]) {
            vec[i].push_back(j);
            done[j] = 1;
          }
        }
      }
    }
    for (int i = 2; i <= n; i *= 2) {
      rem.push_back(i);
    }
    for (int i = 3; i <= n; i++) {
      if (vis[i] || vec[i].size() <= 1) continue;
      if (vec[i].size() & 1) {
        for (int j = 3; j < vec[i].size(); j += 2) {
          res.push_back(make_pair(vec[i][j], vec[i][j + 1]));
        }
        res.push_back(make_pair(i, 3 * i));
        rem.push_back(2 * i);
      } else {
        for (int j = 0; j < vec[i].size(); j += 2) {
          res.push_back(make_pair(vec[i][j], vec[i][j + 1]));
        }
      }
    }
    for (int i = 0; i < rem.size(); i += 2) {
      if (i + 1 < rem.size()) {
        res.push_back(make_pair(rem[i], rem[i + 1]));
      }
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++) {
      printf("%d %d\n", res[i].first, res[i].second);
    }
  }
  return 0;
}
