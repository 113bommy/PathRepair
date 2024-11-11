#include <bits/stdc++.h>
using namespace std;
int N, M;
int arr[15], brr[15];
int main(void) {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) scanf("%d", &arr[i]);
  for (int j = 1; j <= M; j++) scanf("%d", &brr[j]);
  for (int i = 1; i <= N; i++) {
    int pos = 0;
    for (int j = 1; j <= M; j++)
      if (arr[i] == brr[j]) pos = 1;
    if (pos) printf("%d ", arr[i]);
  }
}
