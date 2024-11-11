#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x = i * n + 1;
    cout << x << " ";
  }
}
