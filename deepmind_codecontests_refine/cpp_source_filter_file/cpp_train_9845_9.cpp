#include <bits/stdc++.h>
using namespace std;
int main() {
  char c;
  int n, b = 0, a = 0;
  cin >> n;
  while (n > 0) {
    cin >> c;
    if (c == 'a')
      a++;
    else
      b++;
    n--;
  }
  if (a > b)
    cout << "Anton";
  else if (a < b)
    cout << "Danik";
  else
    cout << "Friendship";
  return 0;
}
