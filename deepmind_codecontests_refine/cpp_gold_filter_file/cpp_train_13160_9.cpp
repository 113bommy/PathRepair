#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 100;
pair<int, int> a[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].first;
  for (int i = 1; i <= n; i++) a[i].second = i;
  sort(a + 1, a + 1 + n);
  int last = a[1].first;
  for (int i = 2; i <= n; i++)
    if (a[i].first > last)
      last = a[i].first;
    else
      a[i].first = ++last;
  for (int i = 1; i <= n; i++) swap(a[i].first, a[i].second);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) cout << a[i].second << " ";
  cout << endl;
  return 0;
}
