#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  cout << 2 - (n & 1) << endl;
  return 0;
}
