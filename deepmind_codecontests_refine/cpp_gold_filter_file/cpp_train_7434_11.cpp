#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, sum, tmp, ans, m, d;
int a[1000010];
char s[1000010];
bool flag;
void quicksort(int x[1000010], int first, int last) {
  int pivot, j, temp, i;
  if (first < last) {
    pivot = first;
    i = first;
    j = last;
    while (i < j) {
      while (x[i] <= x[pivot] && i < last) i++;
      while (x[j] > x[pivot]) j--;
      if (i < j) {
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
      }
    }
    temp = x[pivot];
    x[pivot] = x[j];
    x[j] = temp;
    quicksort(x, first, j - 1);
    quicksort(x, j + 1, last);
  }
}
int main() {
  cin >> n >> d;
  for (i = 0; i < n; i++) cin >> a[i];
  cin >> m;
  sum = 0;
  quicksort(a, 0, n - 1);
  if (m <= n) {
    for (i = 0; i < m; i++) sum += a[i];
  } else {
    for (i = 0; i < n; i++) sum += a[i];
    sum -= d * (m - n);
  }
  cout << sum << endl;
  return 0;
}
