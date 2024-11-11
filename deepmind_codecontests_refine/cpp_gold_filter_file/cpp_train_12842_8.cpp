#include <bits/stdc++.h>
using namespace std;
int arr[1000001];
void seive() {
  arr[1] = 0;
  arr[2] = 1;
  int i = 0;
  for (i = 3; i < 1000001; i++) {
    int j, flag = 0;
    for (j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) arr[i] = 1;
  }
}
int main() {
  seive();
  int a, b, k, t = 0, i;
  cin >> a >> b >> k;
  int u = 1, v = b - a + 1, j = -1;
  while (u <= v) {
    int l = (u + v) / 2, t1 = 0;
    for (i = 0; i < l; i++) {
      if (arr[a + i] == 1) {
        t1++;
      }
    }
    if (t1 < k) {
      u = l + 1;
    } else {
      int flag = 0;
      for (i = 1; i <= b + 1 - l - a; i++) {
        t1 = t1 - arr[a + i - 1] + arr[a + l + i - 1];
        if (t1 < k) {
          u = l + 1;
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        j = l;
        v = l - 1;
      }
    }
  }
  cout << j << endl;
  return (0);
}
