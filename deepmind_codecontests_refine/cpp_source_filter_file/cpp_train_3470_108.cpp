#include <bits/stdc++.h>
using namespace std;
int n, Ans;
int main() {
  cin >> n;
  if (n == 1)
    Ans = 1;
  else if (n == 2)
    Ans = 2;
  else if (n == 3)
    Ans = 1;
  else if (n == 4)
    Ans = 2;
  else
    Ans = 1;
  cout << Ans << endl;
  return 0;
}
