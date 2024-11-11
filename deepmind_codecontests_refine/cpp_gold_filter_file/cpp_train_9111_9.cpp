#include <bits/stdc++.h>
using namespace std;
int a[200005];
vector<int> ans;
int n;
bool ok(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool solven() {
  ans.clear();
  int flg = 0;
  int count = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      count++;
      ans.push_back(a[i]);
      continue;
    }
    if (!flg && ok(a[i] + 1)) {
      flg = 1;
      ans.push_back(a[i]);
    }
  }
  if (count == 0) return 0;
  if (ans.size() > 2) return 1;
  return 0;
}
bool solve2() {
  ans.clear();
  int flg = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (ok(a[i] + a[j])) {
        flg = 1;
        ans.push_back(a[i]);
        ans.push_back(a[j]);
        break;
      }
    }
    if (flg) break;
  }
  if (ans.size() == 2) return 1;
  return 0;
}
bool solve1() {
  ans.clear();
  for (int i = 1; i <= n; i++) {
    if (ok(a[i])) {
      ans.push_back(a[i]);
      break;
    }
  }
  if (ans.size() == 1) return 1;
  return 0;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  if (solven()) {
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  } else if (solve2()) {
    printf("2\n");
    for (int i = 0; i < ans.size(); i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  } else if (solve1()) {
    printf("1\n");
    for (int i = 0; i < ans.size(); i++) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  } else {
    printf("1\n%d\n", a[1]);
  }
}
