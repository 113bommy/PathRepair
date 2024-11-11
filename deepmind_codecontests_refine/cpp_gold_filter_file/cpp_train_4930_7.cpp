#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T alex(T x) {
  return (x > 0) ? x : -x;
}
template <class T>
void read(T& x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while ((ch < 48 || ch > 57) && ch != 45) ch = getchar();
  if (ch == 45) f = -1, ch = getchar();
  while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = getchar();
  x *= f;
}
int n, m;
int a[1000005], ind[1000005];
bool cmp(int x, int y) { return a[x] < a[y] || (a[x] == a[y] && x < y); }
set<int> num;
long long sum1[1000005], sum2[1000005];
double res[1000005];
int main() {
  read(n);
  for (int i = (1); i <= (n); i++) read(a[i]), ind[i] = i;
  sort(ind + 1, ind + n + 1, cmp);
  for (int i = (1); i <= (n); i++) {
    set<int>::iterator it = num.insert(ind[i]).first;
    set<int>::iterator next_it = it, last_it = it;
    int l, r;
    if (last_it != num.begin()) {
      last_it--;
      l = ind[i] - (*last_it) - 1;
    } else
      l = ind[i] - 1;
    next_it++;
    if (next_it != num.end()) {
      r = (*next_it) - ind[i] - 1;
    } else
      r = n - ind[i];
    int mn = min(l, r), mx = max(l, r), vl = a[ind[i]];
    sum1[mn] -= vl;
    sum2[mn + mx + 1] += vl;
    sum2[mx] -= vl;
  }
  for (int i = (n); i >= (1); i--)
    sum1[i] += sum1[i + 1], sum2[i] += sum2[i + 1];
  for (int i = (n); i >= (1); i--)
    sum1[i] += sum1[i + 1], sum2[i] += sum2[i + 1];
  for (int i = (1); i <= (n); i++) {
    res[i] = 1.0 * (sum1[i] + sum2[i]) / (n - i + 1);
  }
  read(m);
  for (int i = (1); i <= (m); i++) {
    int x;
    read(x);
    printf("%.10f\n", res[x]);
  }
  return 0;
}
