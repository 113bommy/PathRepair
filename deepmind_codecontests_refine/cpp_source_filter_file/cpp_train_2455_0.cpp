#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int compare(const void *a, const void *b) {
  if (*(int *)a < *(int *)b)
    return -1;
  else
    return 1;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  qsort(arr, n, sizeof(int), compare);
  cout << arr[(n + 1) / 2];
}
