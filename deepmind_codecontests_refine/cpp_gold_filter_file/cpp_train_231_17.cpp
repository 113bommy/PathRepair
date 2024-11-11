#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, cont = 0;
    cin >> n;
    unordered_map<int, int> mp;
    while (n != 1) {
      if (n % 6 == 0)
        n /= 6;
      else
        n *= 2;
      if (mp[n] == 1) {
        cont = -1;
        goto sw;
      }
      mp[n]++, cont++;
    }
  sw:;
    cout << cont << "\n";
  }
}
