#include <bits/stdc++.h>
using namespace std;
void show(int *arr, int n) {
  int sum = 0;
  for (int i = n - 1; i >= 0; i--)
    if (arr[i] != INT_MAX) sum += arr[i];
  if (sum == 0)
    printf("0");
  else
    for (int i = n - 1; i >= 0; i--)
      if (arr[i] != INT_MAX) printf("%d", arr[i]);
}
int main() {
  bool flag = false;
  int n;
  scanf("%d", &n);
  int arr[n];
  long long sum = 0;
  vector<int> one, two;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
    if (arr[i] % 3 == 1) one.push_back(arr[i]);
    if (arr[i] % 3 == 2) two.push_back(arr[i]);
  }
  sort(arr, arr + n);
  sort(one.begin(), one.end());
  sort(two.begin(), two.end());
  if (arr[0] != 0)
    printf("-1");
  else if (sum == 0)
    printf("0");
  else {
    if (sum % 3 == 0) flag = true;
    if (sum % 3 == 1) {
      if (one.size() > 0) {
        for (int i = 0; i < n; i++)
          if (arr[i] == one[0]) {
            arr[i] = INT_MAX;
            flag = true;
            break;
          }
      } else {
        int counter = 0;
        for (int i = 0; i < n; i++) {
          if (arr[i] % 3 == 2) {
            arr[i] == INT_MAX;
            counter++;
          }
          if (counter == 2) {
            flag = true;
            break;
          }
        }
      }
    }
    if (sum % 3 == 2) {
      if (two.size() != 0) {
        for (int i = 0; i < n; i++)
          if (arr[i] == two[0]) {
            arr[i] = INT_MAX;
            flag = true;
            break;
          }
      } else if (one.size() >= 2) {
        for (int i = 0; i < n; i++)
          if (arr[i] == one[0]) {
            arr[i] = INT_MAX;
            flag = true;
            break;
          }
        for (int i = 0; i < n; i++)
          if (arr[i] == one[1]) {
            arr[i] = INT_MAX;
            flag = true;
            break;
          }
      }
    }
    if (flag)
      show(arr, n);
    else
      printf("-1");
  }
  return 0;
}
