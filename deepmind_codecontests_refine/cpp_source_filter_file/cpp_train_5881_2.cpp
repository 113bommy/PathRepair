#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num = 0;
  string str1, str2;
  char c;
  cin >> n;
  cin >> str1 >> str2;
  for (int i = 0; i < n; i++) {
    if (str1[i] > '4')
      c = str1[i] - 5;
    else
      c = str1[i] + 5;
    num += min(abs(str1[i] - str2[i]), 5 - abs(c - str2[i]));
  }
  cout << num << endl;
}
