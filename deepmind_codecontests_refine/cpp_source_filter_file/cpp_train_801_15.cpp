#include <bits/stdc++.h>
using namespace std;
long long int MIN(long long int a, long long int b) { return (a < b) ? a : b; }
long long int MAX(long long int a, long long int b) { return (a > b) ? a : b; }
long long int ABS(long long int x) { return (x > 0) ? x : -x; }
int MIN(int a, int b) { return (a < b) ? a : b; }
int MAX(int a, int b) { return (a > b) ? a : b; }
int ABS(int x) { return (x > 0) ? x : -x; }
double MIN(double a, double b) { return (a < b) ? a : b; }
double MAX(double a, double b) { return (a > b) ? a : b; }
double ABS(double a, double b) { return (a > 0) ? a : b; }
long long int left(long long int x) { return (x << 1); }
long long int right(long long int x) { return (x << 1) + 1; }
long long int lsone(long long int x) { return (x & (-x)); }
int a[1000000], n, k, d, possible[1000000], t[1000000];
int main() {
  scanf("%d %d %d", &n, &k, &d);
  for (long long int i = 0; i < (long long int)n; i++) scanf("%d", &a[i]);
  sort(a, a + n);
  int l = 0;
  for (int i = 0; i < n; i++) {
    while (l + 1 < n && a[l + 1] - a[i] <= d) l++;
    t[i] = l;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (t[i] == n - 1 && t[i] - i + 1 >= k)
      possible[i] = 1;
    else if (t[i] - i + 1 < k)
      possible[i] = 0;
    else {
      int l = i + k - 1, r = t[i];
      if (possible[l] - possible[r + 2] > 0) possible[i] = 1;
    }
    possible[i] += possible[i + 1];
  }
  if (possible[0] - possible[1] == 1)
    printf("YES\n");
  else
    printf("NO\n");
}
