#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n;
int root;
int v[N];
int ch[N][2];
int cc[N];
int p[N];
vector<pair<int, int> > leaves;
pair<long long, long long> e[N];
int find(int k) {
  pair<int, int> x = make_pair(k, 0);
  int r = lower_bound(leaves.begin(), leaves.end(), x) - leaves.begin();
  int l = max(r - 4, 0), h = min(r + 4, (int)leaves.size());
  for (int j = l; j < h; ++j)
    if (leaves[j].second >= 0) {
      int s = leaves[j].second;
      int vv = leaves[j].first;
      if (j + 1 == leaves.size() && k > vv) return s;
      int pv = leaves[j + 1].first;
      if (pv > k && k > vv) {
        return s;
      }
      if (j == 0 && k < vv) return s;
      pv = leaves[j - 1].first;
      if (pv < k && k < vv) {
        return s;
      }
    }
  return leaves[0].second;
}
void go(int i, long long sum, long long cnt) {
  if (cc[i] == 0) {
    e[i] = make_pair(sum, cnt);
    return;
  }
  if (v[ch[i][0]] > v[ch[i][1]]) swap(ch[i][0], ch[i][1]);
  int s = find(v[i] + 1);
  go(ch[i][0], sum + v[s], cnt + 1);
  s = find(v[i] - 1);
  go(ch[i][1], sum + v[s], cnt + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[i] = 2 * y;
    if (x == -1) {
      root = i;
    } else {
      p[i] = x - 1;
      ch[p[i]][cc[p[i]]++] = i;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (cc[i] == 0)
      leaves.push_back(make_pair(v[i], i));
    else
      leaves.push_back(make_pair(v[i], -1));
  }
  sort(leaves.begin(), leaves.end());
  go(root, 0, 0);
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int k;
    scanf("%d", &k);
    k = 2 * k;
    int s = find(k);
    double r = e[s].first;
    r /= e[s].second;
    printf("%.12lf\n", r / 2);
  }
}
