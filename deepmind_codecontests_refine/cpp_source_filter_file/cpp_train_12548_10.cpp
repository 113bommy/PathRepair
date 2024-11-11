#include <bits/stdc++.h>
using namespace std;
int k = 46;
int proc() {
  for (int i = (int)(k); i <= (int)(2 * 1000 * 1000 * 1000); i++) {
    if ((i % 3 == 0) && (i % 5 == 1)) {
      k = i + 1;
      return i;
    }
  }
}
bool nod(int a, int b) {
  if (a < b) swap(a, b);
  int c;
  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  cout << a;
  if (a == 1)
    return true;
  else
    return false;
}
int main() {
  int n;
  cin >> n;
  if (n == 2) {
    cout << -1;
    return 0;
  }
  cout << 55 << endl << 99 << endl << 45 << endl;
  for (int i = 0; i < (int)(n - 3); i++) {
    cout << proc() << endl;
  }
  return 0;
}
