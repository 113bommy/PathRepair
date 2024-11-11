#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  bool flag = true;
  int n;
  int curr = 0;
  int diff;
  int sum = 0;
  int num;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num;
    if (num - curr <= 15 && flag) {
      curr = num;
      sum = curr;
    } else if (flag) {
      sum += 15;
      flag = false;
    }
  }
  if (90 - sum <= 15 && flag)
    sum = 90;
  else if (n == 1 && num <= 15)
    sum += 15;
  if (sum == num && num < 90) {
    if (num + 15 <= 90)
      sum += 15;
    else
      sum = 90;
  }
  cout << sum;
}
