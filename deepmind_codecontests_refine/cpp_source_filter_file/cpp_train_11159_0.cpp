#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  int n;
  scanf("%d", &n);
  int arr[n + 1];
  int sum = 0;
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    int x = arr[i] / 2;
    sum += x;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      arr[i] = arr[i] / 2;
    } else if (arr[i] < 0 && sum > 0) {
      int x = arr[i] / 2 - 1;
      arr[i] = x;
      sum--;
    } else if (arr[i] > 0 && sum < 0) {
      int x = arr[i] / 2 - 1;
      arr[i] = x;
      sum++;
    } else {
      int x = arr[i] / 2;
      arr[i] = x;
    }
  }
  for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
  return 0;
}
