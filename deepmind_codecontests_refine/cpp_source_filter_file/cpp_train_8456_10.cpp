#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int i = 0;
    long long int x = 0;
    while (true) {
      i++;
      if (n % ((int)pow(2, i) - 1) == 0) {
        x = n / ((int)pow(2, i) - 1);
        break;
      }
    }
    cout << x << endl;
  }
}
