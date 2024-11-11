#include <bits/stdc++.h>
using namespace std;
int main() {
  int oranges;
  int max;
  int d;
  cin >> oranges >> max >> d;
  int temp;
  int j = 0;
  int cnt = 0;
  while (oranges--) {
    cin >> temp;
    if (temp <= max) {
      j += temp;
      if (j >= d) cnt++, j = 0;
    }
  }
  cout << cnt;
}
