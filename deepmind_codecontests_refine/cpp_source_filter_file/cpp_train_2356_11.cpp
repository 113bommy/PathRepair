#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int arr[n];
  int i, cntr = 0;
  for (i = 0; i < n; ++i) {
    scanf("%d", &arr[n]);
  }
  n--;
  for (i = 1; i < n; ++i) {
    if (((arr[i] > arr[i - 1]) && (arr[i] > arr[i + 1])) ||
        ((arr[i] < arr[i - 1]) && (arr[i] < arr[i + 1]))) {
      cntr++;
    }
  }
  cout << cntr << endl;
}
