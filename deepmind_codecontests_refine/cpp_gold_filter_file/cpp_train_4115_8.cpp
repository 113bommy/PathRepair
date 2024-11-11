#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int n;
int arr[MAXN], _arr[MAXN];
int main() {
  scanf("%d", &n);
  int tmp = 1;
  for (int i = 1, j = n; i < j; ++i, --j) {
    arr[i] = arr[j] = 2 * i - 1;
  }
  tmp = 2;
  for (int i = n + 1, j = 2 * n - 1; i < j; ++i, --j) {
    arr[i] = arr[j] = tmp;
    tmp += 2;
  }
  for (int i = 1; i <= 2 * n; ++i) {
    if (arr[i] == 0) arr[i] = n;
    printf("%d ", arr[i]);
  }
  putchar('\n');
}
