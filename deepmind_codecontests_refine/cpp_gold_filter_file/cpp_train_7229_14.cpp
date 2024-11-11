#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, count = 0;
  cin >> n >> m;
  for (; n > 0 && m > 0;) {
    n = n - 1;
    m = m - 1;
    count++;
  }
  if (count % 2 == 0)
    cout << "Malvika";
  else
    cout << "Akshat";
}
