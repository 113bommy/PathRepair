#include <bits/stdc++.h>
using namespace std;
int main() {
  int num = 0;
  int x = 0, y = 2, count = 0;
  cin >> num;
  for (int i = 1; i <= num; i++) {
    if (i % 2 == 0)
      cin >> x;
    else
      cin >> y;
    if (x == y) count++;
  }
  cout << count;
}
