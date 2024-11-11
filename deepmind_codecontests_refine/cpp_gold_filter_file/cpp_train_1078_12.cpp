#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0 || n == 1 || n == 2)
    printf("-1\n");
  else if (n == 3) {
    printf("210\n");
    return 0;
  } else {
    printf("1");
    for (int i = 0; i < n - 4; i++) {
      printf("0");
    }
    n = n % 6;
    if (n == 4)
      cout << "050" << endl;
    else if (n == 5)
      cout << "080" << endl;
    else if (n == 0)
      cout << "170" << endl;
    else if (n == 1)
      cout << "020" << endl;
    else if (n == 2)
      cout << "200" << endl;
    else
      cout << "110" << endl;
  }
}
