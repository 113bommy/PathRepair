#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int inf = 1e9;
int a[maxn];
int main() {
  int n, cur = 0, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    if (a[i] > a[cur]) cur = i;
  for (int i = 0; i < n; i++)
    if (i != cur && a[i] > sum) sum = i;
  cout << cur + 1 << " " << sum << endl;
  return 0;
}
