#include <bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005];
long long int num[1005];
bool fs(int x, int y) { return x > y; }
int main() {
  int n, ka, kb;
  cin >> n >> ka >> kb;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) {
    num[i] = abs(a[i] - b[i]);
  }
  sort(num, num + n, fs);
  int k = ka + kb;
  long long int yy = 0, ss = 0;
  for (int i = num[0] - 1; i > num[0] - 1005 && i >= 0; i--) {
    int s = 0;
    for (int j = 0; j < n; j++) {
      if (num[j] > i)
        s += num[j] - i;
      else
        break;
    }
    if (s <= k) {
      yy = i;
      ss = s;
    } else {
      break;
    }
  }
  long long int sum = 0;
  if (k == 0) {
    for (int i = 0; i < n; i++) {
      sum += num[i] * num[i];
    }
    cout << sum << endl;
    return 0;
  }
  if (yy == 0) {
    if ((k - ss) % 2 == 0)
      sum = 0;
    else
      sum = 1;
  } else {
    if (ss == k) {
      for (int i = 0; i < n; i++) {
        if (num[i] >= yy)
          sum += (yy * yy);
        else
          sum += (num[i] * num[i]);
      }
    } else {
      int r = k - ss;
      for (int i = 0, j = 1; i < n; i++, j++) {
        if (j <= r) {
          sum += (yy - 1) * (yy - 1);
        } else if (num[i] < yy)
          sum += (num[i] * num[i]);
        else
          sum += yy * yy;
      }
    }
  }
  cout << sum << endl;
  return 0;
}
