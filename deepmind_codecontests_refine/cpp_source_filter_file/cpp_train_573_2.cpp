#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == c || b == c) {
    cout << "YES" << endl;
    return 0;
  }
  if (a > c && b > c) {
    cout << "NO" << endl;
    return 0;
  }
  int cur = a;
  int cur_b = b;
  for (int i = 0; i < 10010; i++) {
    for (int i = 0; i < 10010; i++) {
      if ((cur + cur_b) == c) {
        cout << "YES" << endl;
        return 0;
      }
      cur_b += b;
    }
    cur_b = b;
    cur += a;
  }
  cout << "NO" << endl;
  return 0;
}
