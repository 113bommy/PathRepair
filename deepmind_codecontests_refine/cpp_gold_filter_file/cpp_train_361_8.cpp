#include <bits/stdc++.h>
using namespace std;
vector<int> l, m, w;
void gen(int a, int b, vector<pair<pair<int, int>, pair<int, int>>> &xs) {
  int len = b - a + 1;
  if (len == 0) return;
  int end = 3;
  for (int i = 1; i < len; i++) end *= 3;
  xs.reserve(end);
  for (int i = 0; i < end; i++) {
    int cur = i;
    int L = 0;
    int W = 0;
    int M = 0;
    for (int j = 0; j < len; j++) {
      if (cur % 3 == 0) {
        L += l[a + j];
        M += m[a + j];
      } else if (cur % 3 == 1) {
        L += l[a + j];
        W += w[a + j];
      } else {
        M += m[a + j];
        W += w[a + j];
      }
      cur /= 3;
    }
    int a = W - L;
    int b = M - W;
    xs.push_back({{a, b}, {-L, i}});
  }
}
void out(int ans, int ans2) {
  int partA = min(13, (int)l.size());
  int partB = l.size() - partA;
  for (int i = 0; i < partA; i++) {
    if (ans % 3 == 0) {
      printf("LM\n");
    } else if (ans % 3 == 1) {
      printf("LW\n");
    } else
      printf("MW\n");
    ans /= 3;
  }
  ans = ans2;
  for (int i = 0; i < partB; i++) {
    if (ans % 3 == 0) {
      printf("LM\n");
    } else if (ans % 3 == 1) {
      printf("LW\n");
    } else
      printf("MW\n");
    ans /= 3;
  }
}
void solve() {
  int n;
  cin >> n;
  l.resize(n);
  m.resize(n);
  w.resize(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> m[i] >> w[i];
  int partA = min(13, n);
  vector<pair<pair<int, int>, pair<int, int>>> res1, res2;
  gen(0, partA - 1, res1);
  gen(partA, n - 1, res2);
  pair<int, int> result = {-1, -1};
  int resultVal = -1e9;
  bool possible = false;
  if (res2.size()) {
    sort(res2.begin(), res2.end());
    for (auto cur : res1) {
      auto num = cur.first;
      pair<pair<int, int>, pair<int, int>> find = {{-num.first, -num.second},
                                                   {(int)-1e9, (int)-1e9}};
      auto ret = lower_bound(res2.begin(), res2.end(), find);
      if (ret->first == find.first) {
        if (resultVal < (-cur.second.first + -ret->second.first)) {
          result = {cur.second.second, ret->second.second};
          resultVal = -cur.second.first + -ret->second.first;
          possible = true;
        }
      }
    }
  } else {
    for (auto cur : res1) {
      auto num = cur.first;
      auto ans = cur.second;
      ans.first *= -1;
      if (num.first == num.second && num.first == 0) {
        if (resultVal < ans.first) {
          resultVal = ans.first;
          result = {ans.second, 0};
          possible = true;
        }
      }
    }
  }
  if (possible)
    out(result.first, result.second);
  else
    cout << "Impossible";
}
void check() {
  int n;
  cin >> n;
  l.resize(n);
  m.resize(n);
  w.resize(n);
  for (int i = 0; i < n; i++) cin >> l[i] >> m[i] >> w[i];
  vector<string> xs(n);
  for (int i = 0; i < n; i++) cin >> xs[i];
  int L = 0, M = 0, W = 0;
  for (int i = 0; i < n; i++) {
    if (xs[i][0] == 'L' || xs[i][1] == 'L') L += l[i];
    if (xs[i][0] == 'M' || xs[i][1] == 'M') M += m[i];
    if (xs[i][0] == 'W' || xs[i][1] == 'W') W += w[i];
  }
  cout << L << " " << M << " " << W << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
