#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum1 = 0, sum2 = 0;
  char num[51];
  cin >> n;
  cin >> num;
  for (int i = 0; i < n / 2; i++) {
    if (num[i] == '7' || num[i] == '4') {
      sum1 += num[i] - '0';
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (int j = n / 2; j < n; j++) {
    if (num[j] == '7' || num[j] == '4') {
      sum2 += num[j] - '0';
    } else {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (sum1 == sum2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
