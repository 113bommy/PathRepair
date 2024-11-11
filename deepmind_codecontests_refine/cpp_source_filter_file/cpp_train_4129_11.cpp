#include <bits/stdc++.h>
using namespace std;
int main() {
  int num, width, start, end;
  while (cin >> num >> width >> start >> end) {
    int ans;
    int a, b;
    if (end % width == 0) {
      a = width;
    } else
      a = end % width;
    if (start % width == 0) {
      b = width;
    } else
      b = start % width;
    if ((end - 1) / width == (start - 1) / width ||
        (start % width == 1 && end % width == 0) ||
        (start % width == 1 && end == num)) {
      ans = 1;
    } else if (((end + width - 1) / width) - ((start + width - 1) / width) ==
                   1 ||
               start % width == 1 || end % width == 0 || end == num ||
               b - a == 1) {
      ans = 2;
    } else
      ans = 3;
    cout << ans << endl;
  }
  return 0;
}
