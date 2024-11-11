#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[5];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d %d", &arr[i].first, &arr[i].second);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int a = abs(arr[0].first - arr[1].first),
          b = abs(arr[0].second - arr[1].second);
      if (a == b) {
        printf("%d\n", a * b);
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}
