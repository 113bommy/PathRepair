#include <bits/stdc++.h>
using namespace std;
const long long m = 1e9 + 7;
int main() {
  long long a, b;
  cin >> a >> b;
  cout << ((((((((a * (a + 1)) / 2) % m) * b) % m) + a) % m) *
           (((b - 1) * b) / 2) % m) %
              m
       << endl;
}
