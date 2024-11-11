#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    Q;
int n, k, m, r[150000 + 9], onoff[150000 + 9];
void input() {
  int i;
  scanf("%d %d %d", &n, &k, &m);
  for (i = 1; i <= n; i++) scanf("%d", &r[i]);
}
void process() {
  int i, o, x;
  for (i = 1; i <= m; i++) {
    scanf("%d %d", &o, &x);
    if (o == 2) {
      if (onoff[x] == 0)
        printf("NO");
      else
        printf("YES");
      printf("\n");
    } else {
      if (Q.size() < k) {
        onoff[x] = 1;
        Q.push(make_pair(r[x], x));
      } else {
        if (Q.top().first < r[x]) {
          onoff[Q.top().second] = 0;
          Q.pop();
          onoff[x] = 1;
          Q.push(make_pair(r[x], x));
        }
      }
    }
  }
}
int main() {
  input();
  process();
}
