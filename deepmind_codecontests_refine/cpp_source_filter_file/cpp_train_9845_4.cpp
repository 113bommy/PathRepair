#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, d = 0;
  string str;
  cin >> n;
  cin >> str;
  while (n--) {
    if (str[n] == 'A')
      a++;
    else
      d++;
  }
  if (a > d)
    cout << "Anton" << endl;
  else if (a < d)
    cout << "Anton" << endl;
  else
    cout << "Friendship" << endl;
  return 0;
}
