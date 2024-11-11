#include <bits/stdc++.h>
using namespace std;
int n, a[100000 + 10];
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    int _max = 1;
    int k = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] >= a[i - 1])
        k++;
      else
        k = 1;
      if (k > _max) _max = k;
    }
    printf("%d\n", _max);
  }
}
