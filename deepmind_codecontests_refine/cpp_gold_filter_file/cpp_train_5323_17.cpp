#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int ans, num;
  for (int i = 0; i <= n / 4; i++) {
    ans = i * 4;
    num = n - ans;
    if (num % 7 == 0) {
      for (int j = 0; j < i; j++) cout << "4";
      num /= 7;
      for (int j = 0; j < num; j++) cout << "7";
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}
