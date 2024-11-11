#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int arr[N];
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) scanf("%d", arr + i);
  int a = 0, b = arr[n - 1];
  for (i = n - 2; i >= 0; --i) {
    a < b ? a += arr[i] : b += arr[i];
  }
  if (a > b) swap(a, b);
  printf("%d %d", a, b);
}
