#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  int arr[t];
  for (int j = 0; j < t; j++) {
    scanf("%d", &arr[j]);
  }
  int n = sizeof(arr) / sizeof(arr[0]);
  sort(arr, arr + n);
  for (int j = 0; j < t; j++) {
    printf("%d", arr[j]);
  }
  return 0;
}
