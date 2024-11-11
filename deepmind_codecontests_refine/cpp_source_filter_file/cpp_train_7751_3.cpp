#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 21;
const int inf = 1e9 + 7;
vector<int> b[N];
int a[N];
int L[N];
int st[N];
int check[N];
int n, m;
int find(int x) {
  int lo = 0, hi = m;
  int res = 0, g;
  if (m == 0) return 0;
  do {
    g = (lo + hi) >> 1;
    if (a[st[g]] < x) {
      res = g;
      lo = g + 1;
    } else
      hi = g - 1;
  } while (lo <= hi);
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = (int)1; i < (int)n + 1; i++) scanf("%d", &a[i]);
  L[0] = 0;
  a[0] = 0;
  st[0] = 0;
  m = 0;
  for (int i = 1; i <= n; i++) {
    int j = find(a[i]) + 1;
    if (j > m) {
      m = j;
      st[m] = j;
    } else if (a[i] < a[st[j]])
      st[j] = i;
    L[i] = j;
  }
  for (int i = n; i > 0; i--) {
    if (L[i] == m) {
      check[i] = 1;
      if (b[m].size() == 0)
        st[m] = i;
      else if (a[i] > a[st[m]])
        st[m] = i;
      b[m].push_back(i);
    } else {
      int tmp = L[i] + 1;
      int sl = b[tmp].size();
      if (sl != 0) {
        if (a[st[tmp]] > a[i]) {
          if (b[L[i]].size() == 0)
            st[L[i]] = i;
          else if (a[st[L[i]]] < a[i])
            st[L[i]] = i;
          b[L[i]].push_back(i);
          check[i] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++)
    if (check[i] == 0)
      printf("1");
    else {
      if (b[L[i]].size() == 1)
        printf("3");
      else
        printf("2");
    }
  return 0;
}
