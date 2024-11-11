#include <bits/stdc++.h>
using namespace std;
struct P {
  int a, b, i;
  bool operator<(const P &first) const {
    return a < b ? b > first.b : a < first.a;
  }
};
vector<P> a, b;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (u < v)
      a.push_back({u, v, i});
    else
      b.push_back({u, v, i});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<P> &ans = a.size() < b.size() ? b : a;
  printf("%d\n", int(ans.size()));
  for (auto v : ans) printf("%d\n", v.i);
  return 0;
}
