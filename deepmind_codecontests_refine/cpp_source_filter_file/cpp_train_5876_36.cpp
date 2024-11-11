#include <bits/stdc++.h>
using namespace std;
void reverseStr(string& str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++) swap(str[i], str[n - i - 1]);
}
int main() {
  string a, b, c;
  cin >> a;
  cin >> b;
  reverseStr(a);
  if (b == c)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
