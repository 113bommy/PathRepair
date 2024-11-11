#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
int isprime[1000009];
int vis[1000009];
int n;
int MAIN() {
  memset((isprime), (0), sizeof((isprime)));
  for (int i = 2; i <= 1000000; i++) {
    if (isprime[i] == 0) {
      for (int j = i + i; j <= 1000000; j += i) {
        isprime[j] = 1;
      }
    }
    isprime[i] = 1 - isprime[i];
  }
  memset((vis), (0), sizeof((vis)));
  scanf("%d", &n);
  vector<pair<int, int> > ans;
  for (int i = n; i >= 2; i--) {
    if (isprime[i]) {
      vector<int> v;
      v.push_back(i);
      for (int j = i * 3; j <= n; j += i) {
        if (!vis[j]) v.push_back(j);
      }
      if (v.size() % 2 == 0) {
        for (int i = 0; i + 1 < v.size(); i += 2) {
          ans.push_back(make_pair(v[i], v[i + 1]));
          vis[v[i]] = 1;
          vis[v[i + 1]] = 1;
        }
      } else {
        if (2 * i <= n) {
          v.push_back(i * i);
        }
        for (int i = 0; i + 1 < v.size(); i += 2) {
          ans.push_back(make_pair(v[i], v[i + 1]));
          vis[v[i]] = 1;
          vis[v[i + 1]] = 1;
        }
      }
    }
  }
  vector<int> v;
  for (int i = 2; i <= n; i++) {
    if (!vis[i] && i % 2 == 0) v.push_back(i);
  }
  for (int i = 0; i + 1 < v.size(); i += 2) {
    ans.push_back(make_pair(v[i], v[i + 1]));
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
int main() {
  MAIN();
  return 0;
}
