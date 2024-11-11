#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int n, sum;
char a[1000010][30], b[1000010][30];
char tmpc[30];
char tmpchu[30];
int p(int a, int b) {
  int i;
  int sum = 1;
  for (i = 1; i <= b; i++) {
    sum *= a;
  }
  return sum;
}
int inst(int x, char *y, int end) {
  int i;
  for (i = end; i >= x; i--) {
    strcpy(a[i + 1], a[i]);
  }
  strcpy(a[x], y);
  sum++;
  return 0;
}
int main() {
  int i, j;
  int len;
  int tmpo, tmpn;
  int tmpk;
  int tmptop;
  int tmpr;
  char tmpnum[30];
  int flag = 0;
  scanf("%d", &n);
  sum = 1;
  getchar();
  for (i = 1; i <= n; i++) {
    gets(a[i]);
  }
  for (i = 1; i <= n; i++) {
    flag = 0;
    len = strlen(a[i]);
    strcpy(tmpchu, a[i]);
    tmpo = 0;
    tmpn = 0;
    tmpr = 0;
    if (strcmp(tmpchu, "removeMin") == 0) {
      if (q.size() != 0) {
        q.pop();
        goto z;
      } else {
        strcpy(tmpc, "insert");
        tmpc[6] = ' ';
        tmpc[7] = '\0';
        strcpy(tmpnum, "0");
        strcat(tmpc, tmpnum);
        strcpy(b[sum], tmpc);
        sum++;
        goto z;
      }
    }
    for (j = 0; j < len; j++) {
      if (tmpchu[j] == ' ') {
        tmpo = j;
        tmpchu[j] = '\0';
        break;
      }
    }
    if (tmpchu[tmpo + 1] == '-') {
      tmpo++;
    }
    tmpk = len - tmpo - 2;
    for (j = tmpo + 1; j < len; j++) {
      tmpn += (tmpchu[j] - '0') * p(10, tmpk);
      tmpk--;
    }
    if (tmpchu[tmpo] == '-') {
      tmpn = -tmpn;
    }
    if (strcmp(tmpchu, "insert") == 0) {
      q.push(tmpn);
    } else if (strcmp(tmpchu, "getMin") == 0) {
      tmpr = i + 1;
      while (1) {
        if (q.size() != 0) {
          tmptop = q.top();
        } else {
          q.push(tmpn);
          strcpy(tmpc, "insert");
          tmpc[6] = ' ';
          tmpc[7] = '\0';
          sprintf(tmpnum, "%d", tmpn);
          strcat(tmpc, tmpnum);
          strcpy(b[sum], tmpc);
          sum++;
          break;
        }
        if (tmpn > tmptop) {
          q.pop();
          strcpy(b[sum], "removeMin");
          sum++;
        } else if (tmpn < tmptop) {
          q.push(tmpn);
          strcpy(tmpc, "insert");
          tmpc[6] = ' ';
          tmpc[7] = '\0';
          sprintf(tmpnum, "%d", tmpn);
          strcat(tmpc, tmpnum);
          strcpy(b[sum], tmpc);
          sum++;
          break;
        } else {
          break;
        }
      }
    }
  z:
    strcpy(b[sum], a[i]);
    sum++;
  }
  printf("%d\n", sum - 1);
  for (i = 1; i <= sum - 1; i++) {
    puts(b[i]);
  }
  return 0;
}
