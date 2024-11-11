#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c, d;
  bool has_min = false, has_max = false;
  int arr[4], a1, b1, c1, d1;
  cin >> a >> b >> c >> d;
  arr[0] = a.size() - 2;
  arr[1] = b.size() - 2;
  arr[2] = c.size() - 2;
  arr[3] = d.size() - 2;
  a1 = arr[0];
  b1 = arr[1];
  c1 = arr[2];
  d1 = arr[3];
  sort(arr, arr + 4);
  if (arr[0] <= arr[1] / 2) has_min = true;
  if (arr[3] >= 2 * arr[2]) has_max = true;
  if (has_max == true && has_min == true)
    cout << "C" << endl;
  else {
    if (a1 >= 2 * b1 && a1 >= 2 * c1 && a1 >= 2 * d1 ||
        a1 <= b1 / 2 && a1 <= c1 / 2 && a1 <= d1 / 2)
      cout << "A" << endl;
    else if (b1 >= 2 * a1 && b1 >= 2 * c1 && b1 >= 2 * d1 ||
             b1 <= a1 / 2 && b1 <= c1 / 2 && b1 <= d1 / 2)
      cout << "B" << endl;
    else if (c1 >= 2 * a1 && c1 >= 2 * b1 && c1 >= 2 * d1 ||
             c1 <= a1 / 2 && c1 <= b1 / 2 && c1 <= d1 / 2)
      cout << "C" << endl;
    else if (d1 >= 2 * a1 && d1 >= 2 * b1 && d1 >= 2 * c1 ||
             d1 <= a1 / 2 && d1 <= b1 / 2 && d1 <= c1 / 2)
      cout << "D" << endl;
    else
      cout << "C" << endl;
  }
}
