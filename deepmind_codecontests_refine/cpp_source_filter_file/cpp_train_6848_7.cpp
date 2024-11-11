#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << n / 500 * 500 + n % 500 / 5 * 5 << endl;
}
