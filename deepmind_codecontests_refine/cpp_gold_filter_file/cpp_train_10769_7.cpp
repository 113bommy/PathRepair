#include <bits/stdc++.h>
using namespace std;
int i, j, k, n;
bool a[100001], b[100001];
char z[100001];
int main() {
  scanf("%s", &z);
  n = strlen(z);
  for (i = n - 1; i >= 0; i--) {
    a[i] = z[n - i - 1] - '0';
    for (j = i; a[j] && a[j + 1]; j += 2) {
      a[j] = a[j + 1] = 0;
      a[j + 2] = 1;
    }
  }
  scanf("%s", &z);
  n = strlen(z);
  for (i = n - 1; i >= 0; i--) {
    b[i] = z[n - i - 1] - '0';
    for (j = i; b[j] && b[j + 1]; j += 2) {
      b[j] = b[j + 1] = 0;
      b[j + 2] = 1;
    }
  }
  for (i = 100000; i >= 0; i--) {
    if (a[i] > b[i]) {
      cout << ">\n";
      return 0;
    }
    if (a[i] < b[i]) {
      cout << "<\n";
      return 0;
    }
  }
  cout << "=\n";
  return 0;
}
