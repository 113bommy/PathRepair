#include <bits/stdc++.h>
using namespace std;
int n;
int x, y;
long long int a[200100];
long long int t[200100];
long long int sum = 0;
int cur = 1;
double res = 0;
void print() {
  res = sum / ((double)cur);
  printf("%.6lf", res);
}
int main() {
  scanf("%d", &n);
  a[1] = 0;
  for (int i = 1; i <= (n); ++i) {
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d %d", &x, &y);
      t[x] += y;
      sum += x * y;
    } else if (x == 2) {
      scanf("%d", &y);
      cur++;
      ;
      sum += y;
      a[cur] = y;
      t[cur] = 0;
    } else {
      t[cur - 1] += t[cur];
      a[cur] += t[cur];
      sum -= a[cur];
      t[cur] = 0;
      a[cur] = 0;
      cur--;
    }
    print();
  }
  return 0;
}
