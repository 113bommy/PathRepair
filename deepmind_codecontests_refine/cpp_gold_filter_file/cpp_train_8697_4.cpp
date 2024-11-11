#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  int a = 2;
  for (long long i = 0; i < n; ++i) {
    long long m;
    cin >> m;
    if (m % 2 == 0) a = 3 - a;
    cout << a << endl;
  }
}
