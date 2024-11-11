#include <bits/stdc++.h>
using namespace std;
long long n, a[50001];
long long hasil, jum;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    jum += a[i];
  }
  jum /= n;
  for (int i = 1; i < n; i++) {
    if (a[i] < jum) {
      a[i + 1] -= (jum - a[i]);
      hasil += jum - a[i];
    } else if (a[i] > jum) {
      a[i + 1] += a[i] - jum;
      hasil += a[i] - jum;
    }
  }
  cout << hasil << endl;
}
