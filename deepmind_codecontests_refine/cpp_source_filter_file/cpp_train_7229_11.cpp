#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, num, count = 0;
  cin >> n >> m;
  num = n * m;
  while (n) {
    count++;
    num = num - (n - 1) - (m - 1) - 1;
    n--;
    m--;
  }
  if (count % 2) {
    cout << "Akshat";
  } else {
    cout << "Malvika";
  }
}
