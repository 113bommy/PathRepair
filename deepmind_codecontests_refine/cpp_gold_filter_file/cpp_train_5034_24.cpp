#include <bits/stdc++.h>
using namespace std;
int a[100010], n;
vector<int> l, r;
int main() {
  int sum = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i), sum += a[i];
  if (sum % 3) return puts("0"), 0;
  sum /= 3;
  for (int i = 1, j = a[1]; i <= n; i++, j += a[i])
    if (j == sum) l.push_back(i);
  for (int i = n, j = a[n]; i >= 1; i--, j += a[i])
    if (j == sum) r.push_back(i);
  sort(r.begin(), r.end());
  long long ret = 0;
  for (int i = 0; i < ((l).size()); i++) {
    int x = l[i];
    int tmp = r.end() - lower_bound(r.begin(), r.end(), x + 2);
    ret += tmp;
  }
  cout << ret << endl;
  return 0;
}
