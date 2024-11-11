#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int a, k;
  a = (n - 1) / 2;
  k = 1;
  for (int i = 1; i <= (n - 1) / 2; i++) {
    for (int j = 1; j <= a; j++) cout << "*";
    for (int j = 1; j <= k; j++) cout << "D";
    for (int j = 1; j <= a; j++) cout << "*";
    a--;
    k += 2;
    cout << endl;
  }
  for (int i = 1; i <= n; i++) cout << "D";
  cout << endl;
  k -= 2;
  a++;
  for (int i = 1; i <= (n - 1) / 2; i++) {
    for (int j = 1; j <= a; j++) cout << "*";
    for (int j = 1; j <= k; j++) cout << "D";
    for (int j = 1; j <= a; j++) cout << "*";
    a++;
    k -= 2;
    if (i != (n - 1) / 2) cout << endl;
  }
  return 0;
}
