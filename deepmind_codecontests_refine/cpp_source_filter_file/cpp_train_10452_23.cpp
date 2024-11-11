#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c - '0'), c = getchar();
  return x;
}
int n, p, k;
struct order {
  int grey_hairs;
  int displease;
  int idx;
  order(int a = 0, int b = 0, int c = 0) {
    grey_hairs = a;
    displease = b;
    idx = c;
  }
};
bool cmp1(order a, order b) {
  if (a.displease == b.displease) return a.grey_hairs < b.grey_hairs;
  return a.displease > b.displease;
}
bool cmp2(order a, order b) {
  if (a.grey_hairs == b.grey_hairs) return a.displease < b.displease;
  return a.grey_hairs > b.grey_hairs;
}
bool cmp3(order a, order b) { return a.displease >= b.displease; }
vector<order> v;
bool vis[100005];
int main() {
  n = read();
  p = read();
  k = read();
  for (int i = 0; i < n; i++) {
    int a = read(), b = read();
    v.push_back(order(a, b, i));
  }
  p -= k;
  sort(v.begin(), v.end(), cmp1);
  auto v2 = v;
  v2.resize(n - p);
  sort(v2.begin(), v2.end(), cmp2);
  vector<int> ans;
  long long cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < k; i++)
    ans.push_back(v2[i].idx), vis[v2[i].idx] = 1, cnt1 += v2[i].grey_hairs;
  int cnt = 0;
  int i = 0;
  for (i = 0; i < v.size() && cnt < k; i++) {
    cnt += vis[v[i].idx];
  }
  reverse(v.begin(), v.end());
  v.resize(n - i);
  sort(v.begin(), v.end(), cmp1);
  for (int i = 0; i < p; i++) {
    ans.push_back(v[i].idx);
    cnt2 += v[i].displease;
  }
  for (int i = 0; i < ans.size(); i++)
    printf("%d%c", ans[i] + 1, (i + 1 == ans.size() ? '\n' : ' '));
}
