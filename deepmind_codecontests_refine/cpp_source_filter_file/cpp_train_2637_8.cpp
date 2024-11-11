#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; ++i) cin >> arr[i];
  int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == 1)
      c1++;
    else if (arr[i] == 2)
      c2++;
    else if (arr[i] == 3)
      c3++;
    else if (arr[i] == 4)
      c4++;
  }
  int c = 0;
  c += c4;
  c = c + (c2 / 2);
  c2 = c2 % 2;
  if (c3 > c1) {
    c += c3;
    c1 = 0;
  } else {
    c += c3;
    c1 -= c3;
  }
  if (c1 > 4) {
    c = c + (c1 / 4);
    c1 = c1 % 4;
  } else if ((c1 > 0 && c1 <= 2) || c2 > 0) {
    c++;
    c1 -= 2;
  }
  if (c1 > 0) c++;
  cout << c;
}
