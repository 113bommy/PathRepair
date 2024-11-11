#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a = n / 7;
  int b = n % 7;
  const string str = "abcdefg";
  for (int i = 0; i < a; i++) {
    cout << str;
  }
  for (int i = 0; i < b; i++) {
    cout << str[i];
  }
  return 0;
}
