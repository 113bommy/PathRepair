#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int l, r;
  cin >> l >> r;
  cout << "Yes" << endl;
  for (long long int i = l; i <= r; i = i + 2) {
    cout << i << " " << i + 1 << endl;
  }
}
