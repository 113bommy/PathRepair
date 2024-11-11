#include <bits/stdc++.h>
using namespace std;
char s[128], a, *p;
int main() {
  int i, n, sum = 0, conter = 0;
  string arr;
  cin >> arr;
  for (i = 0; i < arr.length(); i++) {
    sum++;
    for (conter = 4; conter && arr[i] == arr[i + 1]; conter--, i++)
      ;
  }
  cout << sum;
  return 0;
}
