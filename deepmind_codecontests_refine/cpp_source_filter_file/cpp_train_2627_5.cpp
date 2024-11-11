#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long int v[200000], b[200000];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%ld", &v[i]);
  }
  long int max = 0;
  cout << v[0] << " ";
  b[0] = v[0];
  for (int i = 1; i < n; i++) {
    if (max > b[i - 1]) max = b[i - 1];
    b[i] = v[i] + max;
    cout << b[i] << " ";
  }
  return 0;
}
