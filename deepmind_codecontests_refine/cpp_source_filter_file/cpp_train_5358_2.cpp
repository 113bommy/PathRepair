#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  long long n = a + b + 1;
  for (int i = b + 1; i <= n; i++) cout << i << " ";
  for (int i = 1; i <= b; i++) cout << i << " ";
  return 0;
}
