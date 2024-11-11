#include <bits/stdc++.h>
using namespace std;
int n, m, arr[100000], flag, maxx;
int main() {
  cin >> n >> m;
  int maxx = 0, falg;
  int tmp1 = 0, sumoff = 0, sumon = 0;
  arr[0] = 0;
  arr[n + 1] = m;
  n++;
  for (int i = 1; i < n; i++) {
    scanf("%d", &arr[i]);
    if (i % 2 == 1) maxx += arr[i] - arr[i - 1];
  }
  if (n % 2 == 1) maxx += m - arr[n - 1];
  int maxxx = maxx;
  for (int i = n; i >= 1; i--) {
    flag = 0;
    if (i % 2 == 0) {
      if (arr[i] - arr[i - 1] > 1)
        flag += sumoff - sumon + arr[i] - arr[i - 1] - 1;
      sumoff += arr[i] - arr[i - 1];
      if (maxx + flag > maxxx) {
        maxxx = maxx + flag;
      }
    } else {
      if (arr[i] - arr[i - 1] > 1) flag += sumoff - sumon - 1;
      if (flag + maxx > maxxx) {
        maxxx = maxx + flag;
      }
      sumon += arr[i] - arr[i - 1];
    }
  }
  cout << maxxx << endl;
}
