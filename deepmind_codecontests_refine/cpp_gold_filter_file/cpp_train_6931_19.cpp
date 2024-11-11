#include <bits/stdc++.h>
using namespace std;
bool isprime(int n) {
  int a = 2;
  while (a * a <= n) {
    if (!(n % a)) return false;
    a++;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << "1" << endl << "1";
  } else if (n == 2) {
    cout << "1" << endl << "1 1";
  } else {
    cout << "2" << endl;
    for (int i = 2; i <= n + 1; i++) {
      if (isprime(i)) {
        cout << "1 ";
      } else {
        cout << "2 ";
      }
    }
  }
}
