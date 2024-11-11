#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t = 0;
  cin >> n >> k;
  int a[50];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= a[k] && a[i] > 0) t++;
  }
  cout << t << endl;
  return 0;
}
