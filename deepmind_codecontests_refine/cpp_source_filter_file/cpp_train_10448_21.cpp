#include <bits/stdc++.h>
using namespace std;
long long v[1000001];
void div() {
  for (long long i = 1; i <= 1000000; i++) {
    for (long long j = i; j * j <= 1000000; j += i) v[j]++;
  }
}
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  div();
  int sum = 0;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++)
      for (int k = 1; k <= c; k++) {
        sum += v[i * j * k];
      }
  }
  sum = sum % 1073741824;
  cout << sum;
  return 0;
}
