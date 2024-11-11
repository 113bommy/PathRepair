#include <bits/stdc++.h>
using namespace std;
int n;
int arr[100005];
struct node {
  int st, ed;
};
struct node segs[100005];
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int i = 0, j = 0, cnt = 0;
    while (j + 1 < n) {
      if (arr[j] < arr[j + 1])
        j++;
      else {
        segs[cnt].st = i;
        segs[cnt].ed = j;
        cnt++;
        i = j = j + 1;
      }
    }
    segs[cnt].st = i;
    segs[cnt].ed = j;
    cnt++;
    if (cnt == 1) {
      cout << n << endl;
      continue;
    }
    int res = 0;
    for (int i = 0; i < cnt - 1; i++) {
      node &n1 = segs[i], &n2 = segs[i + 1];
      int len1 = n1.ed - n1.st + 1, len2 = n2.ed - n2.st + 1;
      if (len1 == 1 || len2 == 1)
        res = max(res, len1 + len2);
      else {
        if (arr[n1.ed - 1] + 1 < arr[n2.st] || arr[n1.ed] + 1 < arr[n2.st + 1])
          res = max(res, len1 + len2);
        else
          res = max(res, max(len1, len2));
      }
    }
    cout << res << endl;
  }
  return 0;
}
