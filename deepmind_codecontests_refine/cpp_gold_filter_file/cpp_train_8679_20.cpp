#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num = 0;
  int sum[3002] = {0};
  int i;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> num;
    sum[num]++;
  }
  i = 1;
  while (true) {
    if (sum[i] == 0) {
      cout << i << endl;
      break;
    }
    i++;
  }
  return 0;
}
