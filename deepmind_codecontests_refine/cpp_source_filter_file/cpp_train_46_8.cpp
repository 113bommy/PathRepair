#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, r;
  long long sum1 = 0, sum2 = 0;
  scanf("%d", &n);
  for (a = 0; a < n; a++) {
    scanf("%d", &r);
    sum1 += r;
  }
  n--;
  for (a = 0; a < n; a++) {
    scanf("%d", &r);
    sum2 += r;
  }
  cout << sum1 - sum2;
  n--;
  for (a = 0, sum1 = 0; a < n; a++) {
    scanf("%d", &r);
    sum1 += r;
  }
  cout << sum2 - sum1;
}
