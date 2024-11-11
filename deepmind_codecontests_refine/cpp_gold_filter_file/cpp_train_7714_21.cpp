#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  long long int l, r;
  cin >> l >> r;
  long long int k = (r - l + 1) / 2;
  cout << "YES" << endl;
  long long int a = l;
  for (int i = 0; i < k; i++) {
    cout << a++ << " ";
    cout << a++ << endl;
  }
  return 0;
}
