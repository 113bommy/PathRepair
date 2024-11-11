#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int i = 1;
  while (((int)(a + 1) / 2) != ((int)(b + 1) / 2)) {
    a = (a + 1) / 2;
    b = (b + 1) / 2;
    i++;
    n /= 2;
  }
  if (n == 2) {
    cout << "Finals!";
  } else {
    cout << i;
  }
  return 0;
}
