#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << n / 36 << " ";
  n %= 36;
  cout << n / 3;
}
