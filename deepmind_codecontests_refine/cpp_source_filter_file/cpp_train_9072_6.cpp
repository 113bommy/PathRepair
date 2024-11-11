#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  bool flag1 = true;
  int count1 = 1, count2 = 1;
  cout << (n + 1) / 2 << endl;
  for (int i = 1; i <= n; i++) {
    if (flag1) {
      cout << count1 << " " << count2 << endl;
      count2++;
      flag1 = false;
    } else {
      cout << count1 << " " << count2 << endl;
      count1++;
      flag1 = true;
    }
  }
}
