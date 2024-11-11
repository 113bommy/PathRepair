#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, no, res = 1000000000, temp;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &no);
    if (k % no == 0) {
      temp = k / no;
      if (temp < res) res = temp;
    }
  }
  cout << res << endl;
  return 0;
}
