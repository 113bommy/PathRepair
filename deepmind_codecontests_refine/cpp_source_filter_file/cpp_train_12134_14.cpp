#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int maxx = 0, count = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] > a[i - 1])
      count++;
    else
      count = 1;
    if (count > maxx) maxx = count;
  }
  cout << maxx;
}
