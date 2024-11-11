#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[15], brr[15];
int main(void) {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
  for (int i = 1; i <= M; i++) scanf("%d", &brr[i]);
  for (int i = 1; i <= N; i++) {
    int pos = 1;
    for (int j = 1; j <= M; j++)
      if (arr[i] != brr[j]) pos = 0;
    if (pos) printf("%d ", arr[i]);
  }
}
