#include <bits/stdc++.h>
using namespace std;
int a[10001];
int main() {
  int n;
  cin >> n;
  int res = 0;
  int temp = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] > temp) {
      temp = a[i];
    } else if (i == temp) {
      res++;
    } else {
      continue;
    }
  }
  cout << ++res;
  return 0;
}
