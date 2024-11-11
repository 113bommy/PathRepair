#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i = 0, j, k, n, m;
  cin >> n >> m;
  long long int arr[100005] = {0};
  while (1) {
    k = n % m;
    if (k == 0) {
      i = 1;
      break;
    } else {
      if (arr[k] > 0) break;
      arr[k]++;
      n = n + k;
    }
  }
  if (i == 1)
    printf("YES");
  else
    printf("NO");
  return 0;
}
