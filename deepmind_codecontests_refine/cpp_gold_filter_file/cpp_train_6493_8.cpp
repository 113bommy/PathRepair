#include <bits/stdc++.h>
using namespace std;
int fibo[2001] = {0};
int main() {
  fibo[1] = 1;
  fibo[2] = 3;
  for (int i = 3; i < 2001; i++) {
    fibo[i] = (2 * fibo[i - 1]) - fibo[i - 2] + (i - 1);
  }
  int a;
  cin >> a;
  cout << fibo[a] << endl;
  return 0;
}
