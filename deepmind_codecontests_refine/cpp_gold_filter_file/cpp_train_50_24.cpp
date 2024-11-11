#include <bits/stdc++.h>
using namespace std;
int main() {
  int b, s, nums[100] = {0}, k, i, a, j, flag = 0;
  cin >> s >> b;
  for (i = 0; i < s; i++) {
    cin >> k;
    for (j = 0; j < k; j++) {
      cin >> a;
      nums[a - 1] = 1;
    }
  }
  for (i = 0; i < b; i++) {
    if (nums[i] == 0) {
      flag = 1;
      break;
    }
  }
  if (flag == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
