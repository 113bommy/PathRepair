#include <bits/stdc++.h>
using namespace std;
int main() {
  int frog;
  cin >> frog;
  for (int i = 0; i < frog; i++) {
    long long int right, left, time;
    cin >> right >> left >> time;
    cout << ((time / 2) * (right - left)) + (right) * (time % 2);
  }
  return 0;
}
