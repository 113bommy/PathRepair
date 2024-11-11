#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  int op = 0;
  if (n >= 5) {
    op += n / 5;
    n /= 5;
  }
  if (n >= 4) {
    op += n / 4;
    n /= 4;
  }
  if (n >= 3) {
    op += n / 3;
    n /= 3;
  }
  if (n == 2) {
    op += n / 2;
    n /= 2;
  } else if (n == 1) {
    op += 1;
  }
  cout << op << endl;
  return 0;
}
