#include <bits/stdc++.h>
using namespace std;
void sort(int a[], int n) {
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[j] > a[i]) {
        tmp = a[j];
        a[j] = a[i];
        a[i] = tmp;
      }
    }
  }
}
int main() {
  int n, s = 0, k = 0, maxim;
  cin >> n;
  int a[n], max[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    max[i] = 1;
  }
  sort(a, n);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      if (a[i] == a[i - 1])
        max[k]++;
      else if (max[k] == 1 || a[i] != a[i - 1])
        k++;
      if (a[i] != a[i - 1]) s++;
    } else
      s++;
  }
  sort(max, n);
  maxim = max[0];
  cout << maxim << ' ' << s;
  return 0;
}
