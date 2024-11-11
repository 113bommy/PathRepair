#include <bits/stdc++.h>
using namespace std;
struct S {
  int a, b;
  S() {}
  S(int _a, int _b) {
    a = _a;
    b = _b;
  }
  const bool operator<(const S &o) const { return a < o.a; }
};
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> mpq;
map<int, int> mp;
stack<int> st;
set<int> set_i;
int arr[200009], num[200009], cnt[200009];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d", &arr[i]);
  }
  int max_n = n, min_n = n;
  int cur = n;
  cnt[cur]++;
  num[0] = cur;
  for (int i = 1; i <= n - 1; i++) {
    cur += arr[i];
    if (cur <= 0 || cur >= 2 * n) {
      printf("-1\n");
      return 0;
    }
    cnt[cur]++;
    max_n = max(max_n, cur);
    min_n = min(min_n, cur);
    num[i] = cur;
  }
  if (max_n - min_n == n - 1) {
    for (int i = min_n; i <= max_n; i++) {
      if (cnt[i] == 0) {
        printf("-1\n");
        return 0;
      }
    }
    int tmp = 1 - min_n;
    for (int i = 0; i < n; i++) {
      printf("%d ", num[i] + tmp);
    }
  } else {
    printf("-1\n");
  }
  return 0;
}
