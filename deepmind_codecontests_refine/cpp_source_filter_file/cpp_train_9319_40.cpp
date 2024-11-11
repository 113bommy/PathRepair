#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 10], b[n + 10];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int ret = 0;
  int sum = 1, gum = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      sum = sum | a[i];
      gum = gum | b[j];
      ret = max(ret, sum + gum);
    }
  }
  cout << ret << endl;
  return 0;
}
