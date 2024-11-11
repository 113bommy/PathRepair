#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 1;
  scanf("%d", &n);
  int arr[n], a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] == c) {
        a[i] = j;
        c++;
        break;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] + 1 << " ";
  }
  return 0;
}
