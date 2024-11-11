#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, q;
int root;
int v[N];
pair<int, int> cs[N];
pair<int, int> sublr[N];
int h[N];
double ans[N];
map<int, int> ord;
int leftmost(int cur) {
  if (sublr[cur].first == -1) {
    if (cs[cur].first == -1)
      sublr[cur].first = cur;
    else
      sublr[cur].first = leftmost(cs[cur].first);
  }
  return sublr[cur].first;
}
int rightmost(int cur) {
  if (sublr[cur].second == -1) {
    if (cs[cur].second == -1)
      sublr[cur].second = cur;
    else
      sublr[cur].second = rightmost(cs[cur].second);
  }
  return sublr[cur].second;
}
void dfs(int cur, int depth, long long sum) {
  h[cur] = depth;
  if (cs[cur].first != -1) {
    dfs(cs[cur].first, depth + 1, sum + v[leftmost(cs[cur].second)]);
    dfs(cs[cur].second, depth + 1, sum + v[rightmost(cs[cur].first)]);
  } else {
    ans[cur] = sum / (double)depth;
  }
}
int main(void) {
  cin >> n;
  fill_n(cs, n, make_pair(-1, -1));
  fill_n(sublr, n, make_pair(-1, -1));
  for (int i = 0; i < n; ++i) {
    int pi;
    cin >> pi >> v[i];
    ord.insert(make_pair(v[i], i));
    if (pi == -1)
      root = i;
    else {
      if (cs[pi - 1].first == -1)
        cs[pi - 1].first = i;
      else {
        cs[pi - 1].second = i;
        if (v[cs[pi - 1].first] > v[cs[pi - 1].second])
          swap(cs[pi - 1].first, cs[pi - 1].second);
      }
    }
  }
  dfs(root, 0, 0);
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    cin >> q;
    map<int, int>::iterator prev = ord.upper_bound(q);
    double res;
    if (prev == ord.begin()) {
      res = ans[prev->second];
    } else if (prev == ord.end()) {
      res = ans[(--prev)->second];
    } else {
      map<int, int>::iterator iter = prev--;
      if (h[prev->second] > h[iter->second])
        res = ans[prev->second];
      else
        res = ans[iter->second];
    }
    printf("%.10lf\n", res);
  }
  return 0;
}
