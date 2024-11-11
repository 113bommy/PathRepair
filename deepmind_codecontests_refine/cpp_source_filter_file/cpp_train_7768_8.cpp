#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x = 0, i;
  cin >> n >> x;
  long long int a[n];
  long long int sum = n - 1;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum = sum + a[i];
  }
  if (x >= sum)
    printf("YES");
  else
    printf("NO");
}
