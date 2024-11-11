#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int lst[N];
set<int> pre[N];
bool p[N];
void sieve() {
  p[0] = p[1] = true;
  for (int i = 2; i * i < N; i++) {
    if (!p[i]) {
      for (int j = i * i; j < N; j += i) {
        p[j] = true;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    lst[i] = 1;
  }
  for (int i = 2; i < N; i++) {
    if (!p[i]) {
      for (int j = i; j < N; j += i) {
        lst[j] = i;
      }
    }
  }
}
int main() {
  sieve();
  int n, res = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    int temp = x, mx = 0;
    while (lst[temp] > 1) {
      int t = lst[temp];
      while (t == lst[temp]) {
        temp /= t;
      }
      if (pre[t].size() == 0) {
        pre[t].insert(0);
      }
      if (pre[t].size()) {
        mx = max(mx, *(--pre[t].end()) + 1);
      }
    }
    temp = x;
    while (lst[temp] > 1) {
      int t = lst[temp];
      while (t == lst[temp]) {
        temp /= t;
      }
      pre[t].insert(mx);
    }
    res = max(res, mx);
  }
  printf("%d", res);
  return 0;
}
