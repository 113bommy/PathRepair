#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  if (n > 30) {
    cout << m << endl;
  } else {
    cout << m % ((int)pow(2, n)) << endl;
  }
  return 0;
}
