#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, m, n, count = 0, sum = 0, sum1 = 0;
  char a[1000], b[1000], c[1000];
  gets(a);
  gets(b);
  gets(c);
  int w = strlen(a);
  int e = strlen(b);
  int r = strlen(c);
  for (i = 0; i < w; i++) {
    if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' ||
        a[i] == 'u') {
      count++;
    }
  }
  for (i = 0; i < e; i++) {
    if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' ||
        b[i] == 'u') {
      sum++;
    }
  }
  for (i = 0; i < r; i++) {
    if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' ||
        c[i] == 'u') {
      sum1++;
    }
  }
  if (count == 5 && sum == 7 && sum1 == 5) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
