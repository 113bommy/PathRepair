#include <bits/stdc++.h>
using namespace std;
int main() {
  int A;
  cin >> A;
  cout << A / 500 * 1000 + A % 1000 / 5 * 5 << endl;
}
