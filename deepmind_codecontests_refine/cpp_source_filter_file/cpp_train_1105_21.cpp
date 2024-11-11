#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5 + 34;
template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &v) {
  os << "(";
  os << v.first << "," << v.second << ")";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  int sz = v.size();
  for (int i = 0; i < sz; ++i) {
    os << v[i];
    if (i != sz - 1) os << ",";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &v) {
  T last = *v.rbegin();
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != last) os << ",";
  }
  os << "]\n";
  return os;
}
vector<int> fact[MM];
void pre() {
  for (int i = 1; i < MM; i++) {
    for (int j = i; j < MM; j += i) {
      fact[j].push_back(i);
    }
  }
}
int dp[MM];
bool done[MM];
int ans[MM];
int cnt = 100;
int grund(int x) {
  if ((x & (x - 1)) == 0) {
    done[x] = 1;
    dp[x] = 0;
  }
  if (done[x]) {
    return dp[x];
  }
  int maxx = fact[2 * x].size() + 5;
  vector<bool> mex(maxx, 0);
  for (int u : fact[2 * x]) {
    if (u == 1) {
      continue;
    }
    int cnt = u;
    int st = (((2 * x) / u) + 1 - u) / 2;
    if ((((2 * x) / u) + 1 - u) % 2) {
      continue;
    }
    int cur = 0;
    if (st <= 0) {
      break;
    }
    for (int i = 0; i < cnt; i++) {
      cur ^= grund(st + i);
    }
    if (cur == 0) {
      ans[x] = min(ans[x], cnt);
    }
    if (cur < maxx) {
      mex[cur] = 1;
    }
  }
  done[x] = 1;
  while (mex[dp[x]]) {
    dp[x]++;
  }
  return dp[x];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre();
  int N;
  cin >> N;
  ans[N] = 1e9;
  int u = grund(N);
  if (u == -1) {
    cout << u << '\n';
    return 0;
  }
  cout << ans[N];
  return 0;
}
