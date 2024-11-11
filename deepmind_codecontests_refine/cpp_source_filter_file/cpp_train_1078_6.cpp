#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << "-1" << endl;
  } else if (n == 3)
    cout << "210" << endl;
  else if ((n - 2) % 6 == 0) {
    if (n > 3) cout << "1";
    for (int i = 0; i <= (n - 1 - 3); i++) cout << "0";
    cout << "200" << endl;
  } else if ((n - 3) % 6 == 0) {
    if (n > 3) cout << "1";
    for (int i = 0; i <= (n - 1 - 3); i++) cout << "0";
    cout << "110" << endl;
  } else if (n == 4 || (n - 4) % 6 == 0) {
    if (n > 2) cout << "1";
    for (int i = 0; i <= (n - 1 - 3); i++) cout << "0";
    cout << "50" << endl;
  } else if (n == 5 || (n - 5) % 6 == 0) {
    if (n > 2) cout << "1";
    for (int i = 0; i <= (n - 1 - 3); i++) cout << "0";
    cout << "80" << endl;
  } else if (n == 6 || (n - 6) % 6 == 0) {
    if (n > 3) cout << "1";
    for (int i = 0; i <= (n - 1 - 2); i++) cout << "0";
    cout << "170" << endl;
  } else if (n == 7 || (n - 7) % 6 == 0) {
    if (n > 2) cout << "1";
    for (int i = 0; i <= (n - 1 - 2); i++) cout << "0";
    cout << "20" << endl;
  }
  cin >> n;
  return 0;
}
