#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 4e6 + 10;
const int MOD = 1e9 + 7;
const long double eps = 1e-12;
int k, n, s[N], e[N], fen[N];
bool is[N];
vector<int> vec;
void add(int pos) {
  for (; pos < N; pos += (pos & -pos)) fen[pos]++;
}
void del(int pos) {
  for (; pos < N; pos += (pos & -pos)) fen[pos]--;
}
int get(int pos) {
  int ret = 0;
  for (; pos > 0; pos -= (pos & -pos)) ret += fen[pos];
  return ret;
}
int main() {
  n = in();
  k = in();
  for (int i = 0; i < n; i++) {
    s[i] = in(), e[i] = in();
    s[i] *= 2, e[i] *= 2;
    e[i]++;
    vec.push_back(s[i]);
    vec.push_back(e[i]);
    vec.push_back(e[i] - 1);
  }
  vec.push_back(-2 * MOD);
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (int i = 0; i < n; i++) {
    s[i] = lower_bound(vec.begin(), vec.end(), s[i]) - vec.begin();
    e[i] = lower_bound(vec.begin(), vec.end(), e[i]) - vec.begin();
    add(s[i]);
    del(e[i]);
  }
  n = vec.size() + 1;
  for (int i = 1; i < n; i++)
    if (get(i) >= k) is[i] = 1;
  vector<pair<int, int> > ans;
  int l = -1, r = -1;
  for (int i = 1; i < n; i++) {
    if (!is[i] && l != -1) {
      ans.push_back({l, r});
      l = -1, r = -1;
      continue;
    }
    if (!is[i]) continue;
    if (l == -1)
      l = i, r = i;
    else
      r = i;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    int l = ans[i].first, r = ans[i].second;
    printf("%d %d\n", vec[l] / 2, vec[r] / 2);
  }
  return 0;
}
