#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int n, t;
  bool flag;
  long long sum;
  while (cin >> n) {
    sum = 0;
    flag = true;
    for (int i = 0; i < n; i++) {
      scanf("%d", &t);
      sum += t;
      if (flag) {
        if (t % 2) flag = false;
      }
    }
    if (sum % 2 || !flag) {
      cout << "First\n";
    } else
      cout << "No\n";
  }
  return 0;
}
