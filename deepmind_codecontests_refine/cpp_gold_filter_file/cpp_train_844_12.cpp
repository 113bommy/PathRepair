#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a = n / 4;
  int b = n % 4;
  const string str = "abcd";
  for (int i = 0; i < a; i++) {
    cout << str;
  }
  for (int i = 0; i < b; i++) {
    cout << str[i];
  }
  return 0;
}
