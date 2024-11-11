#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 11;
set<pair<int, int> >::iterator it;
struct Date1 {
  int a, b, id;
  friend bool operator<(const Date1& a1, const Date1& b1) {
    return a1.a < b1.b;
  }
};
struct Date2 {
  int c, d, id;
  friend bool operator<(const Date2& a1, const Date2& b1) {
    return a1.c < b1.c;
  }
};
Date1 arr1[N];
Date2 arr2[N];
int num[N];
int ans[N];
int n, m;
set<pair<int, int> > sset;
int main() {
  while (scanf("%d", &n) == 1) {
    for (int i = 0; i < n; ++i) {
      scanf("%d %d", &arr1[i].a, &arr1[i].b);
      arr1[i].id = i;
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
      scanf("%d %d %d", &arr2[i].c, &arr2[i].d, &num[i]);
      arr2[i].id = i;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    sset.clear();
    int k = 0;
    for (int i = 0; k < n; ++k) {
      while (i < m && arr2[i].c <= arr1[k].a) {
        if (num[arr2[i].id] > 0) sset.insert(make_pair(arr2[i].d, arr2[i].id));
        ++i;
      }
      it = sset.lower_bound(make_pair(arr1[k].b, 0));
      if (it != sset.end() && (*it).first >= arr1[k].b) {
        ans[arr1[k].id] = (*it).second;
        if (--num[(*it).second] == 0) {
          sset.erase(*it);
        }
      } else
        break;
    }
    if (k != n) {
      printf("NO\n");
    } else {
      printf("YES\n");
      for (int i = 0; i < n; ++i) {
        printf("%d", ans[i] + 1);
        if (i != n - 1)
          printf(" ");
        else
          printf("\n");
      }
    }
  }
}
