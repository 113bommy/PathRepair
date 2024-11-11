#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long L, v, li, ri, count = 0;
    cin >> L >> v >> li >> ri;
    count = (L / v) + (ri / v) + ((li - 1) / v);
    cout << count << endl;
  }
}
