#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count_l, count_r;
  char ch;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ch;
    if (ch == 'L')
      count_l++;
    else if (ch == 'R')
      count_r++;
  }
  cout << count_l + count_r + 1;
}
