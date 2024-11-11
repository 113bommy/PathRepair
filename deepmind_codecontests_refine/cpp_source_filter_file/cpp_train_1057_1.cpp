#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long first, second, z;
  cin >> first >> second >> z;
  unsigned long long a = (first + second) / z;
  unsigned long long b = (first / z) + (second / z);
  if (a == b) {
    cout << a << " " << 0 << "\n";
  } else {
    cout << a << " " << (min(first % z, second % z)) << "\n";
  }
}
