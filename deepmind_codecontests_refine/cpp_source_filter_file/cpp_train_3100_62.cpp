#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  cout << (1000 - (n % 1000)) % 1000;
  return 0;
}
