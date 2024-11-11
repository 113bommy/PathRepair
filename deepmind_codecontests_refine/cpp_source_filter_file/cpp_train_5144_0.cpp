#include <bits/stdc++.h>
using namespace std;
int partition(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = 0; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      int c = arr[i];
      arr[i] = arr[j];
      arr[j] = c;
    }
  }
  int c = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = c;
  return i + 1;
}
void quickSort(int *arr, int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}
int main() {
  int t, n;
  cin >> t >> n;
  int arr[t];
  for (int i = 0; i < t; i++) {
    cin >> arr[i];
  }
  quickSort(arr, 0, t - 1);
  int j = 0, sum = 0;
  while (j < n && arr[j] < 0) {
    sum += arr[j++];
  }
  cout << -sum;
}
