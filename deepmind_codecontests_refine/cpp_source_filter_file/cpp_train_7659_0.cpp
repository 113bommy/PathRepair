#include <bits/stdc++.h>
using namespace std;
const int mn = 100005;
int n, s;
long long v[mn];
vector<int> alist[mn], child[mn];
void getchild(int i, int par) {
  for (int j = 0; j < alist[i].size(); j++)
    if (alist[i][j] != par) {
      getchild(alist[i][j], i);
      child[i].push_back(alist[i][j]);
    }
}
bool cmp(const pair<long long, long long>& p,
         const pair<long long, long long>& q) {
  if (p.first != q.first) return p.first > q.first;
  return p.second > q.second;
}
pair<long long, long long> go(int i) {
  pair<long long, long long> ret = pair<long long, long long>(1, v[i] - 1);
  if (i == s) ret = pair<long long, long long>(0, v[i]);
  vector<pair<long long, long long> > p;
  for (int j = 0; j < child[i].size(); j++) p.push_back(go(child[i][j]));
  sort(p.begin(), p.end(), cmp);
  int k = p.size();
  for (int j = 0; j < k; j++) {
    if (ret.second < 1) break;
    ret.second--;
    ret.first += p[j].first + 1;
  }
  for (int j = 0; j < k; j++) {
    if (ret.second < 1) break;
    long long mi = min(ret.second, p[j].second);
    ret.second -= mi;
    ret.first += mi;
  }
  return ret;
}
int main() {
  n = ({
    int t;
    scanf("%d", &t);
    t;
  });
  for (int i = 0; i < n; i++)
    v[i] = ({
      int t;
      scanf("%d", &t);
      t;
    });
  for (int i = 0; i < n - 1; i++) {
    int u = ({
              int t;
              scanf("%d", &t);
              t;
            }) -
            1,
        v = ({
              int t;
              scanf("%d", &t);
              t;
            }) -
            1;
    alist[u].push_back(v);
    alist[v].push_back(u);
  }
  s = ({
        int t;
        scanf("%d", &t);
        t;
      }) -
      1;
  getchild(s, -1);
  pair<long long, long long> ans = go(s);
  cout << ans.first << endl;
  return 0;
}
