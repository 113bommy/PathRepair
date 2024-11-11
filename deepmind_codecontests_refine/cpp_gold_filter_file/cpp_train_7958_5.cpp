#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int i, j, p, q, l, r, x, y, n;
  cin >> n;
  if (n <= 3) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  string str4 = "4 * 3 = 12\n2 * 1 = 2\n12 * 2 = 24";
  string str5 = "5 * 4 = 20\n2 + 3 = 5\n20 + 5 = 25\n25 - 1 = 24";
  string str6 = "5 * 6 = 30\n4 * 2 = 8\n30 - 8 = 22\n3 - 1 = 2\n22 + 2 = 24";
  string str7 =
      "7 * 6 = 42\n4 * 5 = 20\n42 - 20 = 22\n3 - 2 = 1\n1 + 1 = 2\n22 + 2 = 24";
  int number;
  if ((n - 4) % 4 == 0)
    number = 4;
  else if ((n - 5) % 4 == 0)
    number = 5;
  else if ((n - 6) % 4 == 0)
    number = 6;
  else if ((n - 7) % 4 == 0)
    number = 7;
  int flag = 0, count = 0;
  ;
  for (i = n; i > number; i -= 2) {
    if (!flag)
      cout << i << " - " << i - 1 << " = 1\n";
    else
      cout << i - 1 << " - " << i << " = -1\n";
    flag = !flag;
    count++;
  }
  count /= 2;
  for (i = 0; i < count; i++) {
    cout << "-1 + 1 = 0\n";
  }
  switch (number) {
    case 4:
      cout << str4;
      break;
    case 5:
      cout << str5;
      break;
    case 6:
      cout << str6;
      break;
    case 7:
      cout << str7;
  }
  cout << endl;
  for (i = 0; i < count; i++) {
    cout << "24 + 0 = 24\n";
  }
  return 0;
}
