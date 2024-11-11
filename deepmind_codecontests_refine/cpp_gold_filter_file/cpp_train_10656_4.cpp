#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, a, b;
  int c = 0;
  int temp1 = 1000000000;
  int temp2 = 0;
  scanf("%d", &n);
  int p[100001];
  int q[100001];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    scanf("%d", &b);
    p[i] = a;
    q[i] = b;
  }
  for (int j = 0; j < n; j++) {
    if (q[j] > temp2) {
      temp2 = q[j];
    }
    if (p[j] < temp1) {
      temp1 = p[j];
    }
  }
  for (int k = 0; k < n; k++) {
    if (p[k] == temp1 && q[k] == temp2) {
      c++;
      x = k;
    }
  }
  if (c > 0)
    cout << x + 1;
  else
    cout << "-1";
  return 0;
}
