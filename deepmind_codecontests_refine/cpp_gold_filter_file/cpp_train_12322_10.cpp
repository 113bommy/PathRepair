#include <bits/stdc++.h>
using namespace std;
int s(long long int x) {
  int sum = 0;
  while (x != 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
int main() {
  long long int n;
  cin >> n;
  long long int l = sqrt(n);
  int i = 0;
  while (i < 50) {
    long long int f = (l * l) + (s(l) * (l)) - n;
    if (f == 0) {
      cout << l;
      return 0;
    }
    l++;
    i++;
  }
  i = 0;
  l -= 50;
  while (i < 50) {
    long long int f = (l * l) + (s(l) * (l)) - n;
    if (f == 0) {
      cout << l;
      return 0;
    }
    l--;
    i++;
  }
  cout << -1;
}
