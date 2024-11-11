#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    for (int i = 2; i <= n + 1; i++) cout << i << " ";
    cout << endl;
  }
  return 0;
}
