#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, n, m, prev = 0;
  scanf("%d", &n);
  long long sum = 0, ans = 0;
  for (i = 0; i < n; i++) {
    int h;
    scanf("%d", &h);
    sum += prev - h;
    if (sum < 0) ans += sum, sum = 0;
    prev = h;
  }
  cout << abs(sum) << endl;
  return 0;
}
