#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n, t1, t2, t3;
  t1 = 1;
  t2 = 2;
  t3 = 3;
  cin >> n;
  if (n <= 2) {
    cout << "1\n";
    return 0;
  }
  if (n <= 3) {
    cout << "2\n";
    return 0;
  }
  int cnt = 0;
  while (t3 < n) {
    t3 = t1 + t2;
    t1 = t2;
    t2 = t3;
    cnt++;
  }
  cout << cnt << '\n';
  return 0;
}
