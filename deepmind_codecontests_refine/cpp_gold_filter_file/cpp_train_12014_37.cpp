#include <bits/stdc++.h>
using namespace std;
int a[10000000] = {0}, su[1000005];
void fun() {
  int i, j;
  for (i = 2; i < 1400000; i++)
    for (j = 2; j * i <= 1400000; j++) a[i * j] = 1;
  j = 0;
  for (i = 2; i < 1400000; i++)
    if (a[i] == 0) su[j++] = i;
}
int main() {
  int n;
  fun();
  while (cin >> n) {
    int i;
    for (i = 0; i < n; i++) printf("%d ", su[i]);
    cout << endl;
  }
}
