#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  char a[100];
  char b[100];
  cin >> a;
  cin >> b;
  char p;
  int counter = 0;
  p = a[0];
  int k = 1;
  for (int i = 0; i < strlen(b); ++i) {
    if (b[i] == p) {
      p = a[k++];
      counter++;
    }
  }
  counter++;
  cout << counter;
  return 0;
}
