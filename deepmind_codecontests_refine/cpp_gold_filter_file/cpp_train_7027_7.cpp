#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n;
int k;
struct pnt {
  long long first, second, id;
  pnt(long long first = 0, long long second = 0, long long id = 0)
      : first(first), second(second), id(id){};
} p[202020], q[202020];
bool cmpx(pnt a, pnt b) {
  return a.first != b.first     ? a.first < b.first
         : a.second != b.second ? a.second < b.second
                                : a.id < b.id;
}
bool cmpy(pnt a, pnt b) {
  return a.second != b.second ? a.second < b.second
         : a.first != b.first ? a.first < b.first
                              : a.id < b.id;
}
long long answer;
int flag[202020], flagn;
bool update(int a, int b, int c, int d) {
  long long first = p[b].first - p[a].first;
  long long second = q[d].second - q[c].second;
  if (!first) first = 1;
  if (!second) second = 1;
  if (first & 1) first++;
  if (second & 1) second++;
  if (first * second >= answer) return 1;
  int gas = 0;
  ++flagn;
  for (int i = 0; i < a; i++)
    if (flag[p[i].id] < flagn) {
      flag[p[i].id] = flagn;
      gas++;
    }
  for (int i = b + 1; i < n; i++)
    if (flag[p[i].id] < flagn) {
      flag[p[i].id] = flagn;
      gas++;
    }
  for (int i = 0; i < c; i++)
    if (flag[q[i].id] < flagn) {
      flag[q[i].id] = flagn;
      gas++;
    }
  for (int i = d + 1; i < n; i++)
    if (flag[q[i].id] < flagn) {
      flag[q[i].id] = flagn;
      gas++;
    }
  if (gas > k) return 0;
  answer = first * second;
  return 1;
}
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
    p[i] = q[i] = pnt(a + c, b + d, i);
  }
  sort(p, p + n, cmpx);
  sort(q, q + n, cmpy);
  answer = 1ll * (p[n - 1].first - p[0].first + 2) *
           (q[n - 1].second - q[0].second + 2);
  for (int a = 0; a <= k; a++)
    for (int b = n - 1; b - a >= n - k - 1; b--) {
      for (int c = 0; c <= k; c++)
        for (int d = n - 1; d - c >= n - k - 1; d--) {
          if (!update(a, b, c, d)) break;
        }
    }
  printf("%I64d\n", answer / 4);
  return 0;
}
