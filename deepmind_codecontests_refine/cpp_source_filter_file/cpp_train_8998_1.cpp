#include <bits/stdc++.h>
using namespace std;
int m1[] = {1, 1, 1, 1};
int m2[] = {1, 2, 4, 3};
int m3[] = {1, 3, 4, 2};
int m4[] = {1, 4, 1, 3};
int main() {
  string n;
  cin >> n;
  int len = n.length();
  int num = 0;
  if (len < 2) {
    n = "0" + n;
    len++;
  }
  for (int i = len - 2; i < len; i++) num = (num * 10) + int(n[i] - '0');
  num = num % 4;
  int sum = 1 + m2[num] + m3[num] + m4[num];
  sum = sum % 5;
  cout << sum << endl;
  return 0;
}
