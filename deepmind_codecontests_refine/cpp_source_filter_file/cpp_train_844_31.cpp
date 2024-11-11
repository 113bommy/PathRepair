#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, n, i = 5;
  string s1 = "abcd";
  cin >> n;
  while (n > 0) {
    if (i == 5) i = 0;
    cout << s1[i];
    n--;
    i++;
  }
  return 0;
}
