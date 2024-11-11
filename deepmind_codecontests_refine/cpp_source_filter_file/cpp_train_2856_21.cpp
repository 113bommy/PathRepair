#include <bits/stdc++.h>
using namespace std;
long long get() {
  long long x;
  cin >> x;
  return x;
}
void solve();
int main() {
  solve();
  cout << endl;
  return 0;
}
void solve() {
  long long a[16] = {8848, 958, 12766, 6695,  1100,   807,    31962, 146,
                     20,   25,  134,   10000, 663268, 154103, 1642,  106};
  long long n = get();
  long long ans = 0;
  switch (n) {
    case 1:
      ans = 1;
      break;
    case 2:
      ans = 1;
      break;
    case 3:
      ans = 0;
      break;
    case 4:
      ans = 1;
      break;
    case 5:
      ans = 1;
      break;
    case 6:
      ans = 1;
      break;
    case 7:
      ans = 0;
      break;
    case 8:
      ans = 1;
      break;
    case 9:
      ans = 0;
      break;
    case 10:
      ans = 0;
      break;
    case 11:
      ans = 1;
      break;
    case 12:
      ans = 0;
      break;
    case 13:
      ans = 1;
      break;
    case 14:
      ans = 1;
      break;
    case 15:
      ans = 1;
      break;
    case 16:
      ans = 0;
      break;
  }
  cout << ans;
}
