#include <bits/stdc++.h>
using namespace std;
int arr2[20000], chat[10];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int arr[n][m];
  int arr1[k][2];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
  for (int i = 0; i < k; i++) {
    scanf("%d %d", &arr1[i][0], &arr1[i][1]);
    chat[arr1[i][1] - 1]++;
    arr2[arr1[i][0] - 1]--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (arr[i][j] == 1) arr2[i] += chat[j];
    printf("%d ", arr2[i]);
  }
}
