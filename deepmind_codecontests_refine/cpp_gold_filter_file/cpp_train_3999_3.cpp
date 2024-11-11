#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 1;
  cin >> n;
  int i;
  int pastone;
  cin >> i;
  for (int gg = 0; gg < n - 1; gg++) {
    pastone = i;
    cin >> i;
    if ((i + pastone) == 11) {
      count++;
    }
  }
  cout << count;
  return 0;
}
