#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> cash = {1, 5, 10, 20, 100};
  int i = 4;
  int result = 0;
  int temp;
  while (i >= 0) {
    temp = n / cash[i];
    n -= temp * cash[i];
    result += temp;
    if (n == 0)
      break;
    else
      i--;
  }
  cout << result;
  return 0;
}
