#include <bits/stdc++.h>
using namespace std;
const int inf = (2e9) + 9;
const int maxn = (1e5) + 9;
const long long mod = (1e9) + 7;
stack<int> s;
queue<int> q;
deque<int> d;
int main() {
  int n;
  scanf("%d", &n);
  int maxv = 0, maxs = 0, maxd = 0, v[maxn];
  int i = 0, j, k;
  bool cnts, cntd, cntq;
  while (i < n) {
    maxv = maxs = maxd = 0;
    cnts = cntq = cntd = false;
    k = i;
    while (i < n) {
      scanf("%d", v + i);
      if (v[i] == 0)
        break;
      else
        maxv = max(maxv, v[i]);
      i++;
    }
    for (j = k; j < i; j++) {
      if (v[j] == maxv && !cntq) {
        printf("pushQueue\n");
        cntq = true;
      } else if (maxs <= maxd) {
        if (v[j] < maxs) {
          printf("pushBack\n");
          d.push_back(v[j]);
          cntd = true;
        } else {
          s.push(v[j]);
          printf("pushStack\n");
          maxs = v[j];
          cnts = true;
        }
      } else {
        cntd = true;
        if (v[j] < maxd) {
          printf("pushBack\n");
          d.push_back(v[j]);
        } else {
          printf("pushFront\n");
          d.push_front(v[j]);
          maxd = v[j];
        }
      }
    }
    if (j < n && v[j] == 0) {
      printf("%d", cntd + cntq + cnts);
      if (cnts) printf(" popStack");
      if (cntq) printf(" popQueue");
      if (cntd) printf(" popFront");
      printf("\n");
    }
    i++;
  }
  return 0;
}
