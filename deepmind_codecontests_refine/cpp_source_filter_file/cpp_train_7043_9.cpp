#include <bits/stdc++.h>
using namespace std;
int main() {
  int w, l;
  cin >> w >> l;
  int m = w - 1;
  int a[m];
  int sum = 0;
  for (int i = 0; i < l; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int mini = sum;
  int j = 0;
  for (int i = l; i < m; i++) {
    cin >> a[i];
    sum -= a[j];
    sum += a[i];
    mini = min(sum, mini);
    j++;
  }
  cout << sum;
}
