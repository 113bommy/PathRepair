#include <bits/stdc++.h>
using namespace std;
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}
int solve(int a, int b) {
  if (a > b) swap(a, b);
  if (2 * a >= b) return 4 * a * a;
  return 4 * b * b;
}
int main() {
  int n;
  int a, b;
  cin >> n;
  while (n--) {
    cin >> a >> b;
    cout << solve(a, b) << "\n";
  }
  return 0;
}
