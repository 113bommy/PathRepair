#include <bits/stdc++.h>
using namespace std;
long long n, m, i, j, l, r, poss_rn, poss_rm, poss_n, poss_m, k, ans1, ans2;
priority_queue<tuple<long long, int, int>> pq;
unordered_map<long long, bool> um;
long long f(int x, int y) {
  long long a, b;
  if (x == poss_rn)
    a = poss_n;
  else
    a = 2;
  if (y == poss_rm)
    b = poss_m;
  else
    b = 2;
  return a * b;
}
int main() {
  cin >> n >> m >> r >> k;
  if (n > m) swap(n, m);
  poss_rn = min(r, n - r + 1);
  poss_rm = min(r, m - r + 1);
  ans2 = (n - r + 1) * (m - r + 1);
  poss_n = n - 2 * (poss_rn - 1);
  poss_m = m - 2 * (poss_rm - 1);
  r++;
  pq.push(make_tuple(poss_rn * poss_rm, poss_rn, poss_rm));
  um[poss_rn * r + poss_rm] = true;
  while (k) {
    tie(m, i, j) = pq.top();
    pq.pop();
    l = f(i, j);
    if (l != 0) {
      if (k <= l) {
        ans1 += k * m;
        k = 0;
      } else {
        ans1 += l * m;
        k -= l;
      }
    }
    if (i != 1 && um[(i - 1) * r + j] == false) {
      um[(i - 1) * r + j] = true;
      pq.push(make_tuple((i - 1) * j, i - 1, j));
    }
    if (j != 1 && um[i * r + (j - 1)] == false) {
      --j;
      pq.push(make_tuple(i * j, i, j));
      um[i * r + j] = true;
    }
  }
  printf("%.9f", (double)ans1 / (double)ans2);
  return 0;
}
