#include <bits/stdc++.h>
using namespace std;
int main() {
  string num;
  cin >> num;
  int a = 0, b = 0, c = 0, s = num.size();
  for (int i = 0; i < s; i++) {
    if (num[i] == '1')
      a++;
    else if (num[i] == '2')
      b++;
    else
      c++;
    i++;
  }
  for (int i = 0; i < a; i++) {
    if (i != 0) printf("+");
    printf("1");
  }
  if (b != 0 && a != 0) printf("+");
  for (int i = 0; i < b; i++) {
    if (i != 0) printf("+");
    printf("2");
  }
  if (c != 0 && b != 0 || a != 0) printf("+");
  for (int i = 0; i < c; i++) {
    if (i != 0) printf("+");
    printf("3");
  }
  return 0;
}
