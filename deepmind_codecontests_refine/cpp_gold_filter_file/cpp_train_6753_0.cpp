#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, a[N];
vector<int> ans;

int main() {
  scanf("%d %d", &n, &m);
  int cnt = 0;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &a[i]);
    cnt += (a[i] & 1);
  }
  if (cnt > 2) {
    puts("Impossible");
    return 0;
  }
  for (int i = 2; i < m; i++) {
    if (a[i] & 1) {
      if (a[1] & 1) {
        swap(a[m], a[i]);
      } else {
        swap(a[1], a[i]);
      }
    }
  }
  if (m == 1) {
    if (a[1] > 1) {
      ans.push_back(a[1] - 1);
    }
    ans.push_back(1);
  } else {
    ans.push_back(a[1] + 1);
    for (int i = 2; i < m; i++) {
      ans.push_back(a[i]);
    }
    if (a[m] > 1) {
      ans.push_back(a[m] - 1);
    }
  }
  for (int i = 1; i <= m; i++) {
    printf("%d ", a[i]);
  }
  puts("");
  printf("%d\n", ans.size());
  for (auto a : ans) {
    printf("%d ", a);
  }
  return 0;
}