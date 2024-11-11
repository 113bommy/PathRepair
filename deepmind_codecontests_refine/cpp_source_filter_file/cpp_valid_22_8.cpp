#include <bits/stdc++.h>
#pragma GCC optimize(3)
using namespace std;
int n, k, tot;
int st[55];
bool f;
vector<int> q[55];
long long m[55][55];
set<long long> masks;
void dfs(int now, long long mask, long long submask) {
  if (now == k) {
    if (mask != (1 << n) - 1)
      f = false;
    else if (!masks.count(submask))
      f = false;
    return;
  }
  int sz = (int)q[now].size();
  long long inter = m[now][sz] & (~mask);
  long long ones = m[now][sz] & (submask);
  int lb = __builtin_popcountll(ones), rb = lb + __builtin_popcountll(inter);
  for (int i = lb; i <= rb; i++)
    dfs(now + 1, mask | inter, (submask & (~m[now][sz])) | m[now][i]);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    m[i][0] = 0;
    for (int j = 0; j < x; j++) {
      int y;
      scanf("%d", &y);
      q[i].push_back(y);
      m[i][j + 1] = m[i][j] | (1 << (y - 1));
    }
  }
  if (n == 1) {
    puts("ACCEPTED");
    return 0;
  }
  long long mm = 0;
  masks.insert(mm);
  for (int i = 0; i < n; i++) {
    mm |= (1 << i);
    masks.insert(mm);
  }
  f = true;
  dfs(0, 0, 0);
  if (f)
    puts("ACCEPTED");
  else
    puts("REJECTED");
  return 0;
}
