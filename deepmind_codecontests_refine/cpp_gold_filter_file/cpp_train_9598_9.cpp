#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, num = 0;
  cin >> a >> b >> c;
  int s[a], i;
  for (i = 0; i < a; i++) {
    s[i] = i + 1;
    if (b < s[i] && (a - s[i]) <= c) num++;
  }
  cout << num;
}
