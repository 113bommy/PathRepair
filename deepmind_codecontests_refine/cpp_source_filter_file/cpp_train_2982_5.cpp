#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-9;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n, k;
int a[N], b[N];
set<int> miss;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) miss.insert(i);
  for (int i = 1; i <= k; i++) {
    scanf("%d", &a[i]);
    miss.erase(a[i]);
  }
  stack<int> s;
  int p = 0, q = 1;
  while (q <= k) {
    while ((!s.empty() and s.top() == p + 1) or (a[q] == p + 1 and q <= k)) {
      if (!s.empty() and s.top() == p + 1)
        p++, b[p] = s.top(), s.pop();
      else
        p++, b[p] = a[q], q++;
    }
    if (q > k) break;
    if (!s.empty() and s.top() < a[q])
      return printf("-1\n"), 0;
    else {
      s.push(a[q]), q++;
    }
  }
  for (int i = k + 1; i <= n; i++) {
    while (!s.empty() and s.top() == p + 1) {
      p++, b[p] = s.top(), s.pop();
    }
    if (!s.empty()) {
      auto it = miss.lower_bound(s.top());
      it--;
      if (miss.count(p + 1) and p + 1 >= *it) {
        a[i] = p + 1;
        miss.erase(p + 1);
        p++;
        b[p] = p;
      } else {
        a[i] = *it;
        miss.erase(*it);
        s.push(*it);
      }
    } else {
      int best = *prev(miss.end());
      if (miss.count(p + 1) and p + 1 >= best) {
        a[i] = p + 1;
        miss.erase(p + 1);
        p++;
        b[p] = p;
      } else {
        a[i] = best;
        miss.erase(best);
        s.push(best);
      }
    }
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
