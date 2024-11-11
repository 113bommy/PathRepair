#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
long long mul(long long a, long long b) { return (a * b) % (1000000007); }
long long add(long long a, long long b) { return (a + b) % (1000000007); }
long long sub(long long a, long long b) {
  return ((a - b) % (1000000007) + (1000000007)) % (1000000007);
}
void upd(long long &a, long long b) {
  a = (a % (1000000007) + b % (1000000007)) % (1000000007);
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, w, h;
struct node {
  int id, g, p, t;
};
vector<node> f[300000];
int cmp(node a, node b) {
  if (a.g != b.g) return a.g > b.g;
  if (a.g == 2) {
    return a.p > b.p;
  } else
    return a.p < b.p;
}
int cmp2(node a, node b) {
  if (a.g != b.g) return a.g < b.g;
  if (a.g == 2) {
    return a.p > b.p;
  } else
    return a.p < b.p;
}
pair<int, int> ans[(100000 + 10)];
int main() {
  cin >> n >> w >> h;
  for (int i = 1; i <= n; i++) {
    int g = read(), p = read(), t = read();
    f[t - p + 100000].push_back(node{i, g, p, t});
  }
  for (int xt = 0; xt < 300000; xt++)
    if (((f[xt]).size())) {
      sort((f[xt]).begin(), (f[xt]).end(), cmp2);
      vector<pair<int, int> > vec;
      for (auto v : f[xt]) {
        if (v.g == 1)
          vec.push_back(make_pair(v.p, h));
        else
          vec.push_back(make_pair(w, v.p));
      }
      sort((f[xt]).begin(), (f[xt]).end(), cmp);
      int cnt = 0;
      for (auto v : f[xt]) {
        ans[v.id] = vec[cnt++];
      }
    }
  for (int i = 1; i <= n; i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
