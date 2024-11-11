#include <bits/stdc++.h>
using namespace std;
bool b[100001] = {0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int i, a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int j = 1;
  for (i = 0; i < n; i++) {
    if (a[i] >= j) {
      b[j] = 1;
      j++;
    }
  }
  for (j = 1; j <= 100000; j++) {
    if (b[j] == 0) {
      cout << j;
      break;
    }
  }
  return 0;
}
