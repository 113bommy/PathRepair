#include <bits/stdc++.h>
using namespace std;
int D[1000001], a, b, c;
long long base = 1073741824, sum;
int main() {
  for (int i = 1; i <= 1000000; i++) {
    for (int j = i; j <= 1000000; j += i) D[j]++;
  }
  cin >> a >> b >> c;
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int k = 1; k <= c; k++) {
        sum = (sum + D[i * j * k] % base) % base;
      }
    }
  }
  cout << sum;
}
