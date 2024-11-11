#include <bits/stdc++.h>
using namespace std;
long long int computeLCD(long long int a, long long int b) {
  if (a < b) {
    long long int tmp = a;
    a = b;
    b = tmp;
  }
  long long int tmpA = a;
  long long int tmpB = b;
  while (1) {
    if ((a % b) == 0) break;
    if (b == 1) break;
    long long int tmp = a;
    a = b;
    b = tmp - (tmp / b) * b;
  }
  return (tmpA * tmpB) / b;
}
int main() {
  long long int totalW;
  long long int Ha;
  long long int Hb;
  long long int Wa;
  long long int Wb;
  long long int res = 0;
  cin >> totalW >> Ha >> Hb >> Wa >> Wb;
  long long int diff = Ha * Wb - Hb * Wa;
  if (diff < 0 || (diff == 0 && Wa < Wb)) {
    long long int tmp;
    tmp = Wa;
    Wa = Wb;
    Wb = tmp;
    tmp = Ha;
    Ha = Hb;
    Hb = tmp;
  }
  long long int changeMax = computeLCD(Wa, Wb) / Wa;
  long long int MaxA = totalW / Wa;
  long long int MaxB = totalW / Wb;
  long long int remainW = totalW - MaxA * Wa;
  long long int result1 = MaxA * Ha;
  long long int result2 = 0;
  long long int result3 = MaxB * Hb;
  long long int tmpResult;
  long long int remainStart;
  remainStart = (Wb - (totalW - MaxA * Wa)) / Wa;
  for (long long int i = remainStart; i <= MaxA && i <= changeMax; i++) {
    long long int remain = remainW + i * Wa;
    if (remain % Wb <= remainW) {
      tmpResult = (remain / Wb) * Hb + (MaxA - i) * Ha;
      if (result2 < tmpResult) result2 = tmpResult;
    }
  }
  if (result1 >= result2 && result1 >= result3)
    cout << result1 << endl;
  else if (result2 >= result1 && result2 >= result3)
    cout << result2 << endl;
  else
    cout << result3 << endl;
}
