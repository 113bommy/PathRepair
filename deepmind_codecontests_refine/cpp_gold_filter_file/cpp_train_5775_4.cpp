#include <bits/stdc++.h>
using namespace std;
const int NO = 1000005;
struct X {
  int loop;
  int loopStep;
  int outStep;
  int pre, next;
} p[NO];
char s[NO];
char ans[NO];
int n, m;
void PPP() {
  for (int i = 0, cnt = 0; i != -1; i = p[i].pre, cnt++)
    p[i].outStep = cnt, p[i].loop = 0;
  for (int i = 1; i <= n; i++)
    if (p[i].loop && p[i].loopStep == -1) {
      int st = i, k = p[st].next;
      int loopStep = 1;
      for (; k != st; k = p[k].next) loopStep++;
      for (p[st].loopStep = loopStep, k = p[st].next; k != st; k = p[k].next)
        p[k].loopStep = loopStep;
    }
}
bool mark[NO];
void work() {
  for (int i = 1; ans[i]; i++) ans[i] = 0;
  int len = strlen(s + 1);
  for (int i = 1, loopTime = len - n + 1; i < n; i++)
    if (!mark[i]) {
      if (p[i].loop) {
        int st = i;
        for (int k = loopTime % p[i].loopStep; k; k--) st = p[st].next;
        for (int j = i, k = st; !mark[j];) {
          mark[j] = 1;
          ans[len - (n - k) + 1] = s[j];
          j = p[j].next;
          k = p[k].next;
        }
      } else {
        int Time = len - n + 1;
        if (p[i].outStep <= Time) {
          ans[p[i].outStep] = s[i];
          mark[i] = 1;
        } else {
          int st = i;
          for (int k = Time; k; k--) st = p[st].next;
          mark[i] = 1;
          ans[st + Time] = s[i];
          for (int j = p[i].pre, k = p[st].pre; j != -1;) {
            mark[j] = 1;
            ans[k + Time] = s[j];
            j = p[j].pre;
            k = p[k].pre;
          }
        }
      }
    }
  int Time = len - (n - 1) + 1;
  for (int i = n; s[i]; i++) {
    Time--;
    if (p[n].outStep <= Time)
      ans[i - (n - p[n].outStep)] = s[i];
    else {
      int st = n;
      for (int k = Time; k; k--) st = p[st].next;
      for (int k = st; s[i]; i++) {
        ans[len - (n - k) + 1] = s[i];
        k = p[k].pre;
      }
      break;
    }
  }
}
int main() {
  scanf("%s", ans + 1);
  int ttt;
  scanf("%d", &ttt);
  while (ttt--) {
    for (int i = 1; ans[i]; i++) s[i] = ans[i];
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
      mark[i] = 0, p[i].loop = 1,
      p[i].loopStep = p[i].outStep = p[i].pre = p[i].next = -1;
    for (int i = 1, cnt = 0; i <= m; i++)
      for (int j = i; j <= n; j += m) {
        p[j].next = cnt;
        p[cnt++].pre = j;
      }
    PPP();
    work();
    puts(ans + 1);
  }
  return 0;
}
