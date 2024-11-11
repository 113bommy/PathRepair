#include <bits/stdc++.h>
using namespace std;
int A = 0, B = 0, a1 = 0, b1 = 0;
void playA(int *a, int *b) {
  if (b1 != -1 && a1 != -1) {
    if (b[b1] > a[a1])
      b1--;
    else {
      A += a[a1];
      a1--;
    }
  } else if (b1 == -1) {
    A += a[a1];
    a1--;
  } else {
    b1--;
  }
}
void playB(int *a, int *b) {
  if (b1 != -1 && a1 != -1) {
    if (a[a1] > b[b1])
      a1--;
    else {
      B += b[b1];
      b1--;
    }
  } else if (a1 == -1) {
    B += b[b1];
    b1--;
  } else {
    a1--;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int *a = new int[n];
  int *b = new int[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + n);
  a1 = n - 1;
  b1 = n - 1;
  int flag = 1;
  while (a1 != -1 || b1 != -1) {
    if (flag == 1)
      playA(a, b);
    else
      playB(a, b);
    flag = flag ^ 1;
  }
  cout << A - B << endl;
  return 0;
}
