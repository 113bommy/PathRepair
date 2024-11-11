#include <bits/stdc++.h>
using namespace std;
template <typename T>
void mymax(T &_a, T _b) {
  if (_a < _b) _a = _b;
}
template <typename T>
void mymin(T &_a, T _b) {
  if (_a > _b) _a = _b;
}
template <typename T>
void print(T _x) {
  for (auto _it = _x.begin(); _it != _x.end(); _it++) cout << *_it << " ";
  cout << endl;
}
void print(int _x) { printf("%d ", _x); }
void print(long long _x) { printf("%lld ", _x); }
int n;
vector<int> e[305];
int rinp[305], inp[305];
void unite(deque<int> &a, deque<int> &b) {
  int sza = a.size(), szb = b.size();
  if (sza < szb) {
    while (a.size()) {
      b.push_front(a.back());
      a.pop_back();
    }
    swap(a, b);
    return;
  }
  while (b.size()) {
    a.push_back(b.front());
    b.pop_front();
  }
}
deque<int> ans[305];
int solve(int pos, int fa) {
  ans[pos].push_back(pos);
  vector<pair<int, int> > res;
  for (unsigned int i = 0; i < e[pos].size(); i++)
    if (e[pos][i] != fa) {
      int ret = solve(e[pos][i], pos);
      res.push_back(make_pair(ret, e[pos][i]));
    }
  if (res.size() == 0) return rinp[pos];
  sort(res.begin(), res.end());
  for (unsigned int i = 0; i < res.size(); i++) {
    unite(ans[pos], ans[res[i].second]);
    ans[pos].push_back(pos);
  }
  return res.back().first;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  int leafcnt = 0;
  for (int i = 2; i <= n; i++)
    if (e[i].size() == 1) leafcnt++;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &inp[i]);
    rinp[inp[i]] = i;
  }
  solve(1, -1);
  if ((int)ans[1].size() != 2 * n - 1) {
    print(-1);
    return 0;
  }
  int k = 1;
  for (int i = 0; i < 2 * n - 1; i++)
    if (ans[1][i] == inp[k]) k++;
  if (k != 2 * n - 1) {
    print(-1);
    return 0;
  }
  print(ans[1]);
  return 0;
}
