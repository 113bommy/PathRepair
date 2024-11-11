#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  int count = 0;
  while (a > 1 && b > 2 && c > 4) {
    a -= 1;
    b -= 2;
    c -= 4;
    count += 7;
  }
  cout << count;
  return 0;
}
