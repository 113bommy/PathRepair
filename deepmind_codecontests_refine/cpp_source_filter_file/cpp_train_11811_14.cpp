#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long sum = 0;
  long long temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    sum += temp;
  }
  long long p = (n * (n + 1)) / 2;
  cout << p - sum;
  return 0;
}
