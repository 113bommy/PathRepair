#include <bits/stdc++.h>
using namespace std;
long long int powm(long long int a, int b, int n) {
  long long int rm = 1;
  while (b) {
    if (b % 2) {
      rm = (rm * a) % n;
    }
    a = (a * a) % n;
    b /= 2;
  }
  return rm;
}
int dis[int(500005)] = {0}, no, a[int(500005)], track[int(500005)][3],
    dp[int(500005)] = {0};
int seg[4 * int(500005)];
vector<int> vec[int(500005)];
void go(int ind) {
  if (ind > no) return;
  if (dp[ind] == dp[ind + 1]) {
    go(ind + 1);
    return;
  }
  vec[0].push_back(ind);
  for (int i = int(1); i <= (int)3; i++) vec[0].push_back(track[ind][i - 1]);
  go(track[ind][2] + 1);
}
void update(int n, int it, int f, int l, int Val) {
  if (it == f) {
    seg[n] = Val;
    return;
  }
  int m = (it + f) / 2;
  if (l <= m)
    update(n * 2, it, m, l, Val);
  else
    update(n * 2 + 1, m + 1, f, l, Val);
  seg[n] = min(seg[n * 2], seg[n + 2 + 1]);
}
pair<int, int> query(int n, int it, int f, int l, int r, int Val) {
  if (it == l && r == f) {
    if (seg[n] >= Val) return make_pair(-1, -1);
  }
  if (it == f) {
    if (seg[n] < Val) return make_pair(seg[n], f);
    return make_pair(-1, -1);
  }
  int m = (it + f) / 2;
  if (r <= m)
    return query(n * 2, it, m, l, r, Val);
  else if (l > m)
    return query(n * 2 + 1, m + 1, f, l, r, Val);
  pair<int, int> ans = query(n * 2, it, m, l, m, Val);
  if (ans.first != -1) return ans;
  return query(n * 2 + 1, m + 1, f, m + 1, r, Val);
}
std::map<int, int> hashing;
int main() {
  int n;
  cin >> n;
  no = n;
  for (int i = int(1); i <= (int)n * 4; i++) seg[i] = n + 1;
  for (int i = int(1); i <= (int)n; i++) {
    scanf("%d", &a[i]);
    ;
    dis[i] = a[i];
  }
  sort(dis + 1, dis + n + 1);
  int t = 1;
  for (int i = 2; i <= n; ++i)
    if (dis[i] != dis[i - 1]) dis[++t] = dis[i];
  for (int i = int(1); i <= (int)t; i++) hashing[dis[i]] = i;
  for (int i = int(1); i <= (int)n; i++) a[i] = hashing[a[i]];
  pair<int, int> next, id;
  int trj;
  int szz;
  for (int i = n; i >= 1; i--) {
    next = make_pair(n + 1, n + 1);
    szz = vec[a[i]].size() - 1;
    szz = max(szz, 1);
    for (int j = vec[a[i]].size(); j >= szz; --j) {
      if (vec[a[i]][j - 1] == n) continue;
      id = query(1, 1, n, vec[a[i]][j - 1] + 1, n, vec[a[i]][j - 1]);
      if (id.first == -1) id.first = n + 1, id.second = n + 1;
      if (id.second < next.second) {
        next = id;
        trj = vec[a[i]][j - 1];
      }
    }
    id = next;
    if (id.second <= n && id.second != -1) {
      dp[i] = max(dp[i + 1], 4 + dp[id.second + 1]);
      track[i][0] = id.first;
      track[i][1] = trj;
      track[i][2] = id.second;
    } else
      dp[i] = dp[i + 1];
    for (int j = vec[a[i]].size(); j >= szz; --j) {
      update(1, 1, n, vec[a[i]][j - 1], i);
    }
    vec[a[i]].push_back(i);
  }
  for (int i = int(1); i <= (int)n; i++) a[i] = dis[a[i]];
  for (int i = int(1); i <= (int)t; i++) vec[i].clear();
  go(1);
  printf("%d\n", dp[1]);
  for (int i = int(1); i <= (int)vec[0].size(); i++)
    cout << a[vec[0][i - 1]] << " ";
  cout << endl;
  return 0;
}
