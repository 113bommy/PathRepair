#include <bits/stdc++.h>
using namespace std;
long long int fc(long long int n) {
  if (n == 0) return 1;
  return n * fc(n - 1);
}
int main() {
  long long int n;
  cin >> n;
  cout << (fc(n) / (n * n)) * 2 << endl;
  return 0;
}
