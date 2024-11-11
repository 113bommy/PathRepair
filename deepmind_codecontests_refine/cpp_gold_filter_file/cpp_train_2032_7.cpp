#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int l1, l2;
long long a[2048 + 10], b[2048 + 10];
long long s1, s2;
int len;
struct Node {
  int a, b;
  long long c;
} node[4000000 + 10];
bool cmp(const Node &a, const Node &b) { return a.c < b.c; }
int query(long long x) {
  int l = 0, r = len - 1;
  int pos = 0;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (node[mid].c < x) {
      l = mid + 1;
      pos = l;
    } else {
      r = mid;
      pos = r;
    }
  }
  return pos;
}
int main() {
  while (scanf("%d", &l1) != EOF) {
    s1 = s2 = 0;
    int i;
    pair<int, int> ans1, ans2;
    for (i = 0; i < l1; i++) scanf("%I64d", &a[i]), s1 += a[i];
    scanf("%d", &l2);
    for (i = 0; i < l2; i++) scanf("%I64d", &b[i]), s2 += b[i];
    long long ans = abs(s1 - s2);
    int j;
    int k = 0;
    for (i = 0; i < l1; i++) {
      for (j = 0; j < l2; j++) {
        long long tmp1 = s1 - a[i] + b[j];
        long long tmp2 = s2 - b[j] + a[i];
        long long tmp = abs(tmp1 - tmp2);
        if (tmp < ans) {
          ans1 = make_pair(i, j);
          ans = tmp;
          k = 1;
        }
      }
    }
    len = 0;
    for (i = 0; i < l1; i++) {
      for (j = i + 1; j < l1; j++) {
        node[len].a = i;
        node[len].b = j;
        node[len].c = 2 * (a[i] + a[j]);
        len++;
      }
    }
    sort(node, node + len, cmp);
    if (len) {
      for (i = 0; i < l2; i++) {
        for (j = i + 1; j < l2; j++) {
          long long tmp1 = s2 - b[i] - b[j];
          long long tmp2 = s1 + b[i] + b[j];
          long long cha = (tmp2 - tmp1);
          int id = query(cha);
          int id2 = id - 1;
          if (i == 3 && j == 5) {
            int p = 5;
          }
          tmp1 = s2 - b[i] - b[j] + node[id].c / 2;
          tmp2 = s1 - node[id].c / 2 + b[i] + b[j];
          long long tmp = abs(tmp1 - tmp2);
          if (tmp < ans) {
            ans = tmp;
            ans1 = make_pair(node[id].a, node[id].b);
            ans2 = make_pair(i, j);
            k = 2;
          }
          if (id2 >= 0) {
            tmp1 = s2 - b[i] - b[j] + node[id2].c / 2;
            tmp2 = s1 - node[id2].c / 2 + b[i] + b[j];
            tmp = abs(tmp1 - tmp2);
            if (tmp < ans) {
              ans = tmp;
              ans1 = make_pair(node[id2].a, node[id2].b);
              ans2 = make_pair(i, j);
              k = 2;
            }
          }
        }
      }
    }
    printf("%I64d\n", ans);
    printf("%d\n", k);
    if (k == 2) {
      printf("%d %d\n", ans1.first + 1, ans2.first + 1);
      printf("%d %d\n", ans1.second + 1, ans2.second + 1);
    } else if (k == 1) {
      printf("%d %d\n", ans1.first + 1, ans1.second + 1);
    }
  }
  return 0;
}
