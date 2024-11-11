#include <bits/stdc++.h>
using namespace std;
const int maxn = 105050;
int front, rear;
int n, m, a[maxn], b[maxn];
int In[maxn], q[maxn];
vector<int> son[maxn];
int Ans, L, R;
bool check(int mid) {
  memset(In, 0, sizeof(In));
  for (int i = 1; i <= n; i++) son[i].clear();
  for (int i = 1; i <= mid; i++) {
    In[b[i]]++;
    son[a[i]].push_back(b[i]);
  }
  front = rear = 0;
  for (int i = 1; i <= n; i++) {
    if (In[i] == 0) {
      q[rear++] = i;
    }
  }
  if (front + 1 != rear) return false;
  while (rear < n) {
    int u = q[front++];
    for (int i = 0; i < (int)son[u].size(); i++) {
      In[son[u][i]]--;
      if (In[son[u][i]] == 0) {
        q[rear++] = son[u][i];
      }
    }
    if (front + 1 != rear) return false;
  }
  return true;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i], &b[i]);
  }
  Ans = -1;
  L = 1, R = m;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (check(mid)) {
      Ans = mid;
      R = mid - 1;
    } else
      L = mid + 1;
  }
  printf("%d\n", Ans);
}
