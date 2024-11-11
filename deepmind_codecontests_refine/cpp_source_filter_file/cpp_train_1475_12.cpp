#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n;
  cin >> n;
  int a[n];
  int i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int count = 1;
  int days = 0;
  for (i = 1; i < n; i++) {
    if (a[i] >= count) {
      days++;
      count++;
    } else {
      i++;
    }
  }
  cout << days;
  return 0;
}
