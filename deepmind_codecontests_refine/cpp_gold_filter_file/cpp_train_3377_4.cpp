#include <bits/stdc++.h>
using namespace std;
int n, m;
char c[100001];
int a[100001];
int f[100001];
bool mark[100001];
int cnt;
set<int> s;
void cl() {
  for (set<int>::iterator i = s.begin(); i != s.end(); i++) mark[*i] = true;
  s.clear();
}
int main() {
  memset(f, -1, sizeof(f));
  scanf("%d %d\n", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%c %d\n", &c[i], &a[i]);
    if (f[a[i]] == -1) {
      if (c[i] == '+')
        f[a[i]] = 0;
      else
        f[a[i]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] == 1) cnt++;
    if (f[i] == 0) s.insert(i);
  }
  if (cnt > 0) cl();
  for (int i = 1; i <= m; i++) {
    if (c[i] == '+') {
      f[a[i]] = 1;
      cnt++;
      s.erase(a[i]);
      cl();
    } else {
      f[a[i]] = 0;
      cnt--;
      if (!mark[a[i]]) s.insert(a[i]);
      if (cnt > 0) cl();
    }
  }
  cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!mark[i]) cnt++;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; i++)
    if (!mark[i]) printf("%d ", i);
  printf("\n");
  return 0;
}
