#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl;
    cout << "1" << endl;
  } else {
    int num = 1;
    while (num * (num + 1) < 2 * n) {
      num++;
    }
    num--;
    cout << num << endl;
    for (int i = 1; i < num; i++) {
      cout << i << " ";
      n = n - i;
    }
    cout << n;
  }
  return 0;
}
