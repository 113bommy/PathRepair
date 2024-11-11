#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, i, a, j;
  cin >> n >> k;
  long long ar[k];
  if (k % 2 == 1) {
    a = k / 2 + 1;
    for (i = 0; i < k; i += 2) {
      ar[i] = a;
      a++;
    }
    a = k / 2;
    for (i = 1; i < k; i += 2) {
      ar[i] = a;
      a--;
    }
  } else {
    a = k / 2;
    for (i = 0; i < k; i += 2) {
      ar[i] = a;
      a--;
    }
    a = k / 2 + 1;
    for (i = 1; i < k; i += 2) {
      ar[i] = a;
      a++;
    }
  }
  for (i = 0, j = 0; i < n; i++, j++) {
    if (j == k) j = 0;
    cout << ar[j] << endl;
  }
}
