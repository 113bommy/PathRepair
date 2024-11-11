#include <bits/stdc++.h>
using namespace std;
int find(int a[], int n) {
  int max = 1;
  int m = a[1];
  for (int i = 2; i < n; i++) {
    if (m <= a[i]) {
      max = i;
      m = a[i];
    }
  }
  return max;
}
int main() {
  int c = 0;
  int n;
  cin >> n;
  int a[n];
  cin >> a[0];
  for (int i = 1; i < n; i++) {
    int temp;
    cin >> a[i];
  }
  int m = 0;
  do {
    m = find(a, n);
    if (a[m] > a[0]) {
      a[m]--;
      a[0]++;
      c++;
    } else
      break;
  } while (true);
  cout << c << "\n";
}
