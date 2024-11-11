#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int val = n / 2, i;
  if (n % 2 == 0) {
    cout << val << endl;
    for (i = 1; i <= n / 2; i++) cout << "2 ";
  } else {
    cout << val << endl;
    for (i = 1; i <= n / 2 - 1; i++) cout << "2 ";
    cout << "3";
  }
}
