#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn] = {0};
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int ma = -1;
  int p = 1;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] == a[i])
      p++;
    else {
      ma = max(ma, p);
      p = 1;
    }
    ma = max(ma, p);
  }
  cout << ma << endl;
  return 0;
}
