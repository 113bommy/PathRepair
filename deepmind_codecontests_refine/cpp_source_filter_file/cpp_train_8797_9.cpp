#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, s;
  cin >> n >> s;
  s = n % 5;
  if (s == 0)
    cout << s;
  else
    cout << s + 1;
  return 0;
}
