#include <bits/stdc++.h>
using namespace std;
vector<int> a, b[105], c, t;
int x[105];
int y[105];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    x[i]--;
    y[x[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    x--;
    c.push_back(x);
    a.push_back(i);
  }
  for (int i = 0; i < k; i++) {
    t = a;
    for (int j = 0; j < n; j++) {
      t[j] = a[x[j]];
    }
    a = t;
  }
  b[0] = a;
  for (int i = 1; i <= k * 2; i++) {
    t = a;
    for (int j = 0; j < n; j++) {
      t[j] = a[y[j]];
    }
    a = t;
    b[i] = t;
  }
  bool ok = true;
  for (int i = k; ok && i >= 0; i--) {
    if (i % 2 == 0 && b[i] == c &&
        (i < k - 1 || i == k - 1 && (k == 1 || b[k + 1] != c))) {
      printf("YES\n");
      return 0;
    }
    ok &= b[i] != c;
  }
  ok = true;
  for (int i = k; ok && i <= k * 2; i++) {
    if (i % 2 == 0 && b[i] == c ||
        (i > k + 1 || i == k + 1 && (k == 1 || b[k - 1] != c))) {
      printf("YES\n");
      return 0;
    }
    ok &= b[i] != c;
  }
  printf("NO\n");
  return 0;
}
