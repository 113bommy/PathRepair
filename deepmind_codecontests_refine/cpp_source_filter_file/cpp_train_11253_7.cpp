#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  int n, sq, i, j;
  scanf("%d", &n);
  double qq = sqrt((double)n);
  sq = qq;
  for (i = n; i >= 1; i -= sq) {
    if (i - sq <= 0) break;
    for (j = i - sq + 1; j <= i; j++) a.push_back(j);
  }
  int p = n % sq;
  for (j = 1; j <= p; j++) {
    a.push_back(j);
  }
  for (i = 0; i < n; i++) cout << a[i] << " ";
}
