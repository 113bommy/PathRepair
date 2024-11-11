#include <bits/stdc++.h>
using namespace std;
char S[100005];
int n, last, cnt;
int bein[100005], leaf[100005];
struct SAM {
  int nex[26], link, len;
} A[100005];
void Insert(int c) {
  int p, cur = ++cnt;
  A[cur].len = A[last].len + 1;
  for (p = last; p != -1 && !A[p].nex[c]; p = A[p].link) A[p].nex[c] = cur;
  last = cur;
  leaf[cur] = 1;
  if (p == -1)
    A[cur].link = 0;
  else {
    int q = A[p].nex[c];
    if (A[q].len == A[p].len + 1)
      A[cur].link = q;
    else {
      int clone = ++cnt;
      A[clone] = A[q];
      A[clone].len = A[p].len + 1;
      for (; p != -1 && A[p].nex[c] == q; p = A[p].link) A[p].nex[c] = clone;
      A[cur].link = A[q].link = clone;
    }
  }
}
queue<int> q;
int main() {
  scanf("%s", S);
  n = strlen(S);
  last = cnt = 0;
  A[0].link = -1;
  for (int i = 0; i < n; i++) Insert(S[i] - 'a');
  for (int i = 1; i <= cnt; i++) bein[A[i].link]++;
  for (int i = 1; i <= cnt; i++)
    if (!bein[i]) q.push(i);
  long long ans = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (!x) break;
    bein[A[x].link]--;
    if (!bein[A[x].link]) q.push(A[x].link);
    leaf[A[x].link] += leaf[x];
    ans +=
        (long long)leaf[x] * (leaf[x] + 1) / 2 * (A[x].len - A[A[x].link].len);
  }
  printf("%I64d\n", ans);
}
