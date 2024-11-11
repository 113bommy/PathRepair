#include <bits/stdc++.h>
using namespace std;
int a[109], n, k;
bool cmp(int a, int b) { return a < b; }
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1, cmp);
  cout << a[k];
  return 0;
}
