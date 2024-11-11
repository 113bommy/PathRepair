#include <bits/stdc++.h>
using namespace std;
int n;
int arr[101000];
int maxi, mini;
int num[3];
int tmp[3];
int main() {
  scanf("%d", &n);
  maxi = -101000;
  mini = 101000;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    mini = min(arr[i], mini);
    maxi = max(arr[i], maxi);
  }
  if (maxi - mini <= 1) {
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] == mini) {
      num[0]++;
    } else if (arr[i] == mini + 1) {
      num[1]++;
    } else {
      num[2]++;
    }
  }
  tmp[0] = num[0] + num[1] / 2;
  tmp[1] = num[1] - (num[1] / 2) * 2;
  tmp[2] = num[2] + num[1] / 2;
  int ans[3];
  ans[0] = tmp[0];
  ans[1] = tmp[1];
  ans[2] = tmp[2];
  int minis = 987654321;
  while (1) {
    int now = 0;
    for (int i = 0; i < 3; i++) {
      now += min(tmp[i], num[i]);
    }
    if (minis > now) {
      for (int i = 0; i < 3; i++) {
        arr[i] = tmp[i];
      }
      minis = now;
    }
    if (tmp[0] == 0 || tmp[2] == 0) break;
    tmp[0]--;
    tmp[2]--;
    tmp[1] += 2;
  }
  printf("%d\n", minis);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < ans[i]; j++) {
      printf("%d ", mini + i);
    }
  }
}
