#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  unsigned int n;
  cin >> n;
  cout << (n % 2 ? --n >> 2 : 0) << endl;
  return 0;
}
