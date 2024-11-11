#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n;
  long long a = 0;
  for (long long i = 0; i < n; i++) {
    cin >> m;
    a += (m - 1) * i + 1;
  }
  cout << a << endl;
}
