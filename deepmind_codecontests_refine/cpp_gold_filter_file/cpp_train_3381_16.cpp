#include <bits/stdc++.h>
using namespace std;
int a, b, second, cnt;
int main() {
  cin >> a >> b >> second;
  cnt = abs(a) + abs(b);
  if (cnt <= second && (cnt - second) % 2 == 0)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
