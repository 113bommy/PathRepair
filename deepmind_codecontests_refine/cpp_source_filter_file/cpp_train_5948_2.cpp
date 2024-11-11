#include <bits/stdc++.h>
using namespace std;
char o[56], p[12];
int a, i, b, j;
int main() {
  scanf("%d", &a);
  for (i = 0; i < a; i++) {
    cin >> o[i];
  }
  j = 0;
  while (b <= a) {
    p[j] = o[b];
    j++;
    b = b + j;
  }
  for (i = 0; i < j; i++) {
    cout << p[i];
  }
  return 0;
}
