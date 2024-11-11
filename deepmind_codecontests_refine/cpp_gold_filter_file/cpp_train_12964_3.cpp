#include <bits/stdc++.h>
using namespace std;
const int N = 150000 + 5;
int check(int a[], int n) {
  for (int i = 1; i < n; i++) {
    if (i & 1) {
      if (a[i] >= a[i + 1]) return 0;
    } else {
      if (a[i] <= a[i + 1]) return 0;
    }
  }
  return 1;
}
int a[N];
int n;
int ok(int i) {
  if (i < 1 || i > n) return 1;
  if (i & 1) {
    if (i + 1 <= n && a[i] >= a[i + 1]) return 0;
    if (i - 1 >= 1 && a[i] >= a[i - 1]) return 0;
  } else {
    if (i + 1 <= n && a[i] <= a[i + 1]) return 0;
    if (i - 1 >= 1 && a[i] <= a[i - 1]) return 0;
  }
  return 1;
}
int Ok(int i) { return ok(i) && ok(i - 1) && ok(i + 1); }
void work() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  vector<pair<int, int> > ans;
  for (int i = 1; i < n; i++) {
    if ((i & 1) && a[i] >= a[i + 1] || (~i & 1) && a[i] <= a[i + 1]) {
      int c = 0;
      for (int j = i + 2; j < n; j++) {
        if ((j & 1) && a[j] >= a[j + 1] || (~j & 1) && a[j] <= a[j + 1]) {
          if (++c > 2) {
            puts("0");
            return;
          }
          swap(a[i], a[j]);
          if (check(a, n)) ans.push_back(make_pair(i, j));
          swap(a[i], a[j]);
          swap(a[i + 1], a[j]);
          if (check(a, n)) ans.push_back(make_pair(i + 1, j));
          swap(a[i + 1], a[j]);
          swap(a[i], a[j + 1]);
          if (check(a, n)) ans.push_back(make_pair(i, j + 1));
          swap(a[i], a[j + 1]);
          swap(a[i + 1], a[j + 1]);
          if (check(a, n)) ans.push_back(make_pair(i + 1, j + 1));
          swap(a[i + 1], a[j + 1]);
        }
      }
      if (c == 0) {
        for (int j = 1; j <= n; j++) {
          for (int k = i; k <= i + 1; k++) {
            swap(a[j], a[k]);
            if (Ok(j) && Ok(k)) {
              if (j < k)
                ans.push_back(make_pair(j, k));
              else
                ans.push_back(make_pair(k, j));
            }
            swap(a[j], a[k]);
          }
        }
      }
      break;
    }
  }
  sort(ans.begin(), ans.end());
  printf("%d\n", unique(ans.begin(), ans.end()) - ans.begin());
  return;
}
int main() {
  work();
  return 0;
}
