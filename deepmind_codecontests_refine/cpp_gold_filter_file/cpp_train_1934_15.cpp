#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
  int n;
  cin >> n;
  int flag = 0;
  if (n & 1) {
    n -= 3;
    flag = 1;
  }
  cout << n / 2 + flag << "\n";
  for (int i = 1; i <= n / 2; i++) cout << "2 ";
  if (flag) cout << 3;
  return 0;
}
