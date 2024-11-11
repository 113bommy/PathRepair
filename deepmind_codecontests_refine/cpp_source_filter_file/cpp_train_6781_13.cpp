#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int last[MAXN] = {};
vector<int> div(int n) {
  vector<int> d;
  int i;
  for (i = 1; i * i < n; i++)
    if (!(n % i)) {
      d.push_back(i);
      d.push_back(n / i);
    }
  if (i * i == n) d.push_back(n);
  return d;
}
int main() {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d%d", &x, &y);
    vector<int> d = div(x);
    int D = d.size(), res = 0;
    for (int j = 0; j < D; j++)
      if (last[d[j]] < i - y) res++;
    for (int j = 0; j < D; j++) last[d[j]] = i;
    printf("%d\n", res);
  }
}
