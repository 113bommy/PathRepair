#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tc;
  cin >> tc;
  for (int p = 1; p <= tc; p++) {
    long long int n;
    cin >> n;
    for (long long int i = 2; i <= n + 1; i++) {
      cout << i << " ";
    }
    cout << endl;
  }
}
