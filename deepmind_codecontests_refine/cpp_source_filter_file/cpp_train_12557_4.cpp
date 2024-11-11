#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> ans;
  for (int x = n - 1; x >= max(0, n - 1000); x--) {
    int sum = 0;
    int tmp = x;
    while (tmp > 0) {
      sum += tmp % 10;
      tmp /= 10;
    }
    if (x + sum == n) {
      ans.push_back(x);
    }
  }
  sort(ans.rbegin(), ans.rend());
  printf("%d\n", (int)ans.size());
  for (int x : ans) {
    printf("%d\n", x);
  }
}
