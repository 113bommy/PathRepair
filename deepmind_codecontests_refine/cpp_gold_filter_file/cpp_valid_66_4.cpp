#include <bits/stdc++.h>
using namespace std;
bool checkNum(int number) {
  if (number % 10 == 3 || number % 3 == 0) return false;
  return true;
}
void solve() {
  int k, count = 0, number = 1;
  cin >> k;
  while (count < k) {
    if (checkNum(number)) count++;
    number++;
  }
  cout << number - 1 << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
