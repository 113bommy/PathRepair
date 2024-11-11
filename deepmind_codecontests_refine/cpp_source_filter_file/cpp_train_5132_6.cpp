#include <bits/stdc++.h>
using namespace std;
int main() {
  string stra, strb;
  cin >> stra >> strb;
  int num1 = 0;
  int num2 = 0;
  for (int i = 0; i < stra.size(); ++i)
    if (stra[i] != strb[i])
      if (stra[i] == '4')
        num1++;
      else
        num2++;
  cout << min(num1, num2);
  return 0;
}
