#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x = i * 2 + n;
    cout << x << " ";
  }
}
