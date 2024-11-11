#include <bits/stdc++.h>
using namespace std;
map<char, int> counts;
string a;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    cout << (n == 2 ? 2 : (n % 2 == 1)) << '\n';
  }
}
