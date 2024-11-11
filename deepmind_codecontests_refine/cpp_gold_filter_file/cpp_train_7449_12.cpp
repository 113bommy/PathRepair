#include <bits/stdc++.h>
using namespace std;
struct node {
  long long a;
  int id;
} s[2000000];
bool operator<(node x, node y) { return fabs(x.a) > fabs(y.a); }
priority_queue<node> q;
long long b[200333];
int main() {
  int k, x;
  int n;
  scanf("%d", &n);
  scanf("%d%d", &k, &x);
  int count = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &s[i].a);
    s[i].id = i;
    if (s[i].a < 0) count++;
  }
  for (int i = 1; i <= n; i++) {
    q.push(s[i]);
  }
  while (k != 0) {
    k--;
    node temp = q.top();
    q.pop();
    if (count & 1) {
      if (temp.a >= 0) {
        temp.a += x;
        q.push(temp);
      } else {
        temp.a -= x;
        q.push(temp);
      }
    } else {
      if (temp.a >= 0) {
        temp.a -= x;
        if (temp.a < 0) count++;
        q.push(temp);
      } else {
        temp.a += x;
        if (temp.a >= 0) count++;
        q.push(temp);
      }
    }
  }
  while (!q.empty()) {
    node temp = q.top();
    q.pop();
    b[temp.id] = temp.a;
  }
  for (int i = 1; i <= n; i++) {
    if (i == 1)
      printf("%I64d", b[i]);
    else
      printf(" %I64d", b[i]);
  }
  printf("\n");
}
