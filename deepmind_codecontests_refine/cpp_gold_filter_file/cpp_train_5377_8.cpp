#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num = 0, i = 1;
  cin >> n;
  while (i <= n - 1) {
    if ((n - i) % i == 0) {
      num++;
    }
    i++;
  }
  cout << num;
}
