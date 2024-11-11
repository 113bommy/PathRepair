#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 6};
  int x, y;
  cin >> x >> y;
  long long ans = 0;
  for (int i = x; i < y + 1; i++) {
    int num = i;
    while (num > 0) {
      ans += a[num % 10];
      num /= 10;
    }
  }
  cout << ans;
}
