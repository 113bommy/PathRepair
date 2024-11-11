#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[3];
  cin >> a[0] >> a[1] >> a[2];
  cout << "First" << endl;
  cout << max(a[0], max(a[1], a[2])) - min(a[0], min(a[1], a[2])) << endl;
  int mov;
  cin >> mov;
  mov--;
  a[mov] += max(a[0], max(a[1], a[2])) - min(a[0], min(a[1], a[2]));
  long long max_e = max(a[0], max(a[1], a[2]));
  long long min_e = min(a[0], min(a[1], a[2]));
  long long mid_e = a[0] + a[1] + a[2] - max_e - min_e;
  cout << 2 * max_e - min_e - mid_e << endl;
  cin >> mov;
  mov--;
  if (a[mov] == mid_e) {
    cout << max_e - min_e << endl;
  }
  if (a[mov] == min_e) {
    cout << max_e - mid_e << endl;
  }
}
