#include <bits/stdc++.h>
using namespace std;
int main() {
  int chest = 0, bicept = 0, back = 0, n, x;
  cin >> n;
  for (int i = 1; n != 0; i++) {
    n--;
    cin >> x;
    if (i == 1)
      chest += x;
    else if (i == 2)
      bicept += x;
    else if (i == 3) {
      back += x;
      i = 1;
    }
  }
  if (chest > bicept && chest > back)
    cout << "chest";
  else if (bicept > chest && bicept > back)
    cout << "bicept";
  else if (back > chest && back > bicept)
    cout << "back";
  return 0;
}
