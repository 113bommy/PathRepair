#include <bits/stdc++.h>
using namespace std;
char s[400005];
int aa[400005][2];
struct cmp1 {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
  }
};
priority_queue<pair<int, int>, vector<pair<int, int> >, cmp1> q;
int cmp(const void *aa, const void *bb) {
  int *a = (int *)aa;
  int *b = (int *)bb;
  return *(a) - *(b);
}
int main() {
  int n, m = 0;
  pair<int, int> a;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &aa[i][0]);
    aa[i][1] = i + 1;
  }
  qsort(aa, n, sizeof(aa[0]), cmp);
  scanf("%s", s);
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '0') {
      printf("%d ", aa[m][1]);
      q.push(make_pair(aa[m][0], aa[m][1]));
      m++;
    } else {
      a = q.top();
      q.pop();
      printf("%d ", a.second);
    }
  }
  return 0;
}
