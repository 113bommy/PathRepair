#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n;
  cin >> n;
  if (n % 4 >= 2) return puts("-1"), 0;
  for (int i = 1; i <= n / 2; i += 2) {
    a[i] = i + 1;
    a[i + 1] = n - i + 1;
    a[n - i + 1] = n - i;
    a[n - i] = i;
  }
  if (n % 2 == 1) a[n / 2 + 1] = n / 2 + 1;
  for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
  return 0;
}
