#include <bits/stdc++.h>
using namespace std;
const int N = 100010, LOG = 60;
int n, arr[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr, arr + n);
  long long sum = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (i < n - 1 && arr[i] == arr[i + 1]) cnt++;
    if (i < n - 2 && arr[i] == arr[i + 1] + 1 && arr[i + 1] == arr[i + 2]) {
      puts("cslnb");
      return 0;
    }
    arr[i] -= i;
    sum += arr[i];
    if (arr[i] < 0) {
      puts("cslnb");
      return 0;
    }
  }
  if (cnt > 1 || ((sum & 1) == 0))
    puts("cslnb");
  else
    puts("sjfnb");
  return 0;
}
