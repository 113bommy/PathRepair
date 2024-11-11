#include <bits/stdc++.h>
using namespace std;
long long ar[10];
int main() {
  int n, m, i, j, k;
  long long s = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    ar[p - 1]++;
  }
  for (i = 0; i < m - 1; i++) {
    for (j = i + 1; j < m; j++) {
      s += ar[i] * ar[j];
    }
  }
  cout << s;
  return 0;
}
