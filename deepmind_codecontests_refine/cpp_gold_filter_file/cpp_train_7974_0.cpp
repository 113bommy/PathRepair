#include <bits/stdc++.h>
using namespace std;
unsigned long long int powe(int a, int b) {
  if (b == 0) return 1;
  unsigned long long int s = 1LL << (b);
  return s;
}
int main() {
  unsigned long long int m, n;
  cin >> m >> n;
  unsigned long long int a[m][n];
  for (unsigned long long int i = 0; i < m; i++) {
    for (unsigned long long int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  unsigned long long int count = 0, o = 1;
  for (unsigned long long int i = 0; i < m; i++) {
    unsigned long long int c1 = 0, c2 = 0;
    for (unsigned long long int j = 0; j < n; j++) {
      if (a[i][j] == 1)
        c1++;
      else
        c2++;
    }
    count = count + powe(2, c1) - o + powe(2, c2) - o;
  }
  for (unsigned long long int j = 0; j < n; j++) {
    unsigned long long int c1 = 0, c2 = 0;
    for (unsigned long long int i = 0; i < m; i++) {
      if (a[i][j] == 1)
        c1++;
      else
        c2++;
    }
    count = count + powe(2, c1) - o + powe(2, c2) - o;
  }
  count -= m * n;
  cout << count << endl;
}
