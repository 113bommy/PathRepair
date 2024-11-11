#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  int n, m;
  if (k % 2 == 0) {
    int a = k / 2;
    if (a >= 19) {
      cout << "-1" << endl;
      exit(0);
    }
    for (int i = 0; i < a; i++) cout << "8";
  } else {
    int a = (k - 1) / 2;
    if (a >= 18) {
      cout << "-1" << endl;
      exit(0);
    }
    for (int i = 0; i < a; i++) cout << "8";
    cout << "4";
  }
  cout << endl;
  return 0;
}
