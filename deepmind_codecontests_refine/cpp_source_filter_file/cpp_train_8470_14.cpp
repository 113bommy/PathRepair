#include <bits/stdc++.h>
using namespace std;
int difDigits(int y) {
  set<int> x;
  x.insert(y % 10);
  y /= 10;
  x.insert(y % 10);
  y /= 10;
  x.insert(y % 10);
  y /= 10;
  x.insert(y % 10);
  y /= 10;
  return x.size();
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int year;
  cin >> year;
  for (int i = year + 1; i < 9000; ++i)
    if (difDigits(i) == 4) {
      cout << i;
      break;
    }
  return 0;
}
