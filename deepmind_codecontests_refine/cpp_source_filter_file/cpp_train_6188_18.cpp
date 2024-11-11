#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, temp;
  cin >> n >> a >> b;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    cout << (a * temp) % b << " ";
  }
  return 0;
}
