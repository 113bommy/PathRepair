#include <bits/stdc++.h>
using namespace std;
static int a[30];
int main() {
  int n, k;
  cin >> n >> k;
  getchar();
  for (int i = 0; i < n; ++i) {
    char c = getchar() - 'A';
    a[c]++;
  }
  int min = 1e9;
  for (int i = 0; i < k; ++i) {
    if (a[i] < min) min = a[i];
  }
  cout << min * k;
  return 0;
}
