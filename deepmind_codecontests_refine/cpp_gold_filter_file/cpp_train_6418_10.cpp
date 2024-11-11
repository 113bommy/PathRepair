#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  srand(time(NULL));
  ;
  int n;
  cin >> n;
  int a[110];
  int res = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    res += a[i];
  }
  sort(a, a + n);
  int i = 0;
  while (a[i] < 0 && i < n) {
    res += abs(2 * a[i]);
    i++;
  }
  cout << res << endl;
  return 0;
}
