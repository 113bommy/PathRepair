#include <bits/stdc++.h>
using namespace std;
set<int> s;
int visited[200100], A[200100];
int main() {
  int i, j, k, n, p, q, pik, sum = 0;
  scanf("%d%d%d", &n, &p, &q);
  scanf("%d", &pik);
  for (i = 0; i < 200100; i++) visited[i] = false;
  for (i = 0; i < pik; i++) {
    scanf("%d", &A[i]);
    s.insert(A[i]);
    visited[A[i]] = true;
  }
  int last = 1;
  visited[n + 1] = true;
  for (i = 0; i <= n + 1; i++) {
    if (visited[i] == true) {
      sum += (i - last) / (q + 1);
      last = i;
    }
  }
  s.insert(0);
  s.insert(n + 1);
  set<int>::iterator it;
  int l, r, m;
  if (sum >= p) {
    printf("-1\n");
    return 0;
  }
  for (i = pik - 1; i >= 0; i--) {
    it = s.find(A[i]);
    it--;
    l = *it;
    it++;
    m = *it;
    it++;
    r = *it;
    it--;
    s.erase(it);
    sum += (r - l) / (q + 1) - (r - m) / (q + 1) - (m - l) / (q + 1);
    if (sum >= p) {
      printf("%d\n", i + 1);
      return 0;
    }
  }
  printf("%d\n", -1);
  return 0;
}
