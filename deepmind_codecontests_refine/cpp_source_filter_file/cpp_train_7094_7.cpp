#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int T, n, cnt, now[N], ans[N];
char ch[N];
vector<int> A, B, C;
map<pair<int, int>, bool> col;
inline void ask() {
  if (!A.size()) return;
  printf("Q %d ", (int)A.size());
  for (int i = 0; i < A.size(); i++) printf("%d %d ", A[i], B[i]);
  puts("");
  fflush(stdout);
  scanf("%s", ch + 1);
  for (int i = 0; i < A.size(); i++)
    col[make_pair(A[i], B[i])] = (ch[i + 1] == '1');
}
int main() {
  scanf("%d", &T);
  while (T--) {
    cnt = 0;
    col.clear();
    memset(ans, 0, sizeof(ans));
    scanf("%d", &n);
    A.clear();
    B.clear();
    for (int i = 2; i <= n; i += 2) {
      A.push_back(i - 1);
      B.push_back(i);
    }
    ask();
    A.clear();
    B.clear();
    for (int i = 3; i <= n; i += 2) {
      A.push_back(i - 1);
      B.push_back(i);
    }
    ask();
    now[++cnt] = 1;
    for (int i = 2; i <= n; i++)
      if (!col[make_pair(i - 1, i)]) now[++cnt] = i;
    A.clear();
    B.clear();
    for (int i = 3; i <= cnt; i += 4)
      A.push_back(now[i - 2]), B.push_back(now[i]);
    for (int i = 4; i <= cnt; i += 4)
      A.push_back(now[i - 2]), B.push_back(now[i]);
    ask();
    A.clear();
    B.clear();
    for (int i = 3; i <= cnt; i += 4)
      A.push_back(now[i]), B.push_back(now[i + 2]);
    for (int i = 4; i <= cnt; i += 4)
      A.push_back(now[i]), B.push_back(now[i + 2]);
    ask();
    ans[now[1]] = 1;
    if (cnt > 1) ans[now[2]] = 2;
    for (int i = 3; i <= cnt; i++) {
      if (col[make_pair(now[i - 2], now[i])])
        ans[now[i]] = ans[now[i - 2]];
      else
        ans[now[i]] = 6 - ans[now[i - 2]] - ans[now[i - 1]];
    }
    A.clear();
    B.clear();
    C.clear();
    for (int i = 1, t; i <= n; i++) {
      if (ans[i]) t = ans[i];
      ans[i] = t;
      if (ans[i] == 1)
        A.push_back(i);
      else if (ans[i] == 2)
        B.push_back(i);
      else if (ans[i] == 3)
        C.push_back(i);
    }
    printf("A %d %d %d\n", (int)A.size(), (int)B.size(), (int)C.size());
    for (int i = 0; i < A.size(); i++) printf("%d ", A[i]);
    puts("");
    for (int i = 0; i < B.size(); i++) printf("%d ", B[i]);
    puts("");
    for (int i = 0; i < C.size(); i++) printf("%d ", C[i]);
    puts("");
    fflush(stdout);
  }
}
