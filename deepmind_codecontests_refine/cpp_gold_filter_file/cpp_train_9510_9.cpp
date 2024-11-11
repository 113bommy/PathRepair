#include <bits/stdc++.h>
using namespace std;
int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
int main() {
  int n;
  cin >> n;
  int* arr = new int[n];
  int* rez = new int[n];
  for (int j = 0; j < n; ++j) {
    cin >> arr[j];
    rez[j] = arr[j];
  }
  if (n == 1)
    cout << 1;
  else {
    qsort(arr, n, sizeof(int), compare);
    int j = 1;
    for (j = 1; j < n; ++j) {
      if (arr[j] == arr[j - 1]) {
        cout << "Still Rozdil";
        break;
      } else {
        for (int i = 0; i < n; ++i)
          if (rez[i] == arr[j - 1]) {
            cout << i + 1;
            goto l;
          }
      }
    }
  }
l:
  return 0;
}
