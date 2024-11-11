#include <bits/stdc++.h>
using namespace std;
int count_zero(int n) {
  int result = 0;
  while (n) {
    result += n / 5;
    n = n / 5;
  }
  return result;
}
int solve(int m) {
  int flag = 0;
  for (int i = 0; i < 1000000; i++) {
    if (count_zero(i) == m) {
      cout << "5" << endl;
      cout << i << " " << i + 1 << " " << i + 2 << " " << i + 3 << " " << i + 4
           << " ";
      flag = 1;
      break;
    }
  }
  if (flag == 1) {
    return 0;
  } else {
    return 1;
  }
}
int main() {
  int m;
  cin >> m;
  int flag = solve(m);
  if (flag == 1) {
    cout << "0";
  }
}
