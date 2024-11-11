#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
  int arr[100001];
  int n, tmp1, tmp2;
  scanf("%d", &n);
  for (int i = 0; i < 100001; ++i) {
    arr[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &tmp2, &tmp1);
    if (++arr[tmp1] < tmp2) {
      printf("NO");
      return 0;
    }
    if (tmp2 < arr[tmp1]) --arr[tmp1];
  }
  printf("YES");
  return 0;
}
