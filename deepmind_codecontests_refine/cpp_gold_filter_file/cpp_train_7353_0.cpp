#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
int n, x;
int main() {
  scanf("%d", &n);
  for (int j = 0; j < n; ++j) {
    scanf("%d", &x);
    arr[x]++;
  }
  for (int j = 1; j <= N - 10; ++j) {
    if (arr[j] % 2 != 0) {
      printf("Conan");
      return 0;
    }
  }
  printf("Agasa");
  return 0;
}
