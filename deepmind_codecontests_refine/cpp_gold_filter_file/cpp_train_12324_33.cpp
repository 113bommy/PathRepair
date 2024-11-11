#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin.ignore(3, '\n');
    r += 2 * (getchar() == '+' || getchar() == '+') - 1;
  }
  cout << r;
}
