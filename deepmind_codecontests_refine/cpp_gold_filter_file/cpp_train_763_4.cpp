#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  int m;
  int tempn;
  scanf("%d", &tempn);
  scanf("%d", &m);
  n = (long long)tempn;
  long long a[1000001];
  for (int i = 0; i < n + 1; i++) {
    a[i] = 0;
  }
  if (n == 1 || n == 2) {
    cout << 0 << endl;
    return 0;
  }
  long long x = (n * (n - 1) * (n - 2)) / 6;
  for (int i = 0; i < m; i++) {
    int tempx;
    scanf("%d", &tempx);
    a[tempx]++;
    scanf("%d", &tempx);
    a[tempx]++;
  }
  long long tempx = 0;
  for (int i = 0; i < n + 1; i++) {
    tempx += (n - 1 - a[i]) * a[i];
  }
  tempx /= 2;
  cout << x - tempx << endl;
  return 0;
}
