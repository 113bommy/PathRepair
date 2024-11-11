#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<pair<pair<int, int>, int> > black, white;
int n, m, pre[N], usewhite[N], useblack[N];
int find(int x) { return pre[x] = (x == pre[x] ? x : find(pre[x])); }
int merge(int a, int b) {
  int ra = find(a), rb = find(b);
  if (ra == rb) return 0;
  pre[ra] = rb;
  return 1;
}
void init() {
  for (int i = 1; i <= n; i++) pre[i] = i;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v;
    char str[5];
    scanf("%d %d %s", &u, &v, str);
    if (str[0] == 'S')
      black.push_back(make_pair(make_pair(u, v), i + 1));
    else
      white.push_back(make_pair(make_pair(u, v), i + 1));
  }
  if ((n % 2 == 0) || m < n - 1 || white.size() < n / 2 ||
      black.size() < n / 2) {
    puts("-1");
    return 0;
  };
  init();
  for (int i = 0; i < black.size(); i++)
    merge(black[i].first.first, black[i].first.second);
  int cnt = 0;
  for (int i = 0; i < white.size(); i++)
    if (merge(white[i].first.first, white[i].first.second))
      cnt++, usewhite[i] = 1;
  if (cnt > n / 2) {
    puts("-1");
    return 0;
  };
  init();
  for (int i = 0; i < white.size(); i++)
    if (usewhite[i]) merge(white[i].first.first, white[i].first.second);
  for (int i = 0; i < white.size(); i++)
    if (cnt < n / 2 && merge(white[i].first.first, white[i].first.second))
      usewhite[i] = 1, cnt++;
  if (cnt < n / 2) {
    puts("-1");
    return 0;
  };
  for (int i = 0; i < black.size(); i++)
    if (merge(black[i].first.first, black[i].first.second))
      useblack[i] = 1, cnt++;
  if (cnt < n - 1) {
    puts("-1");
    return 0;
  };
  printf("%d\n", n - 1);
  for (int i = 0; i < white.size(); i++)
    if (usewhite[i]) printf("%d ", white[i].second);
  for (int i = 0; i < black.size(); i++)
    if (useblack[i]) printf("%d ", black[i].second);
  return 0;
}
