#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, y;
  int left = 0, right = 0;
  cin >> n;
  while (n--) {
    cin >> x >> y;
    if (x > 0 && y >= 0)
      left++;
    else if (x > 0 && y <= 0)
      left++;
    else if (x < 0 && y >= 0)
      right++;
    else
      right++;
  }
  if (left <= 1 || right <= 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
