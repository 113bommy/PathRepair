#include <bits/stdc++.h>
using namespace std;
int main() {
  char c, last;
  while (cin >> c) {
    if (isupper(c) || islower(c)) last = c;
  }
  if (isupper(last)) tolower(last);
  if (last == 'a' || last == 'e' || last == 'i' || last == 'o' || last == 'u' ||
      last == 'y')
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
