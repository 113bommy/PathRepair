#include <bits/stdc++.h>
using namespace std;
int isprime(int);
int ispalin(int);
int main() {
  int n = -1, p, q, size = 1200001;
  cin >> p >> q;
  int pr = 0, pl = 0;
  int a[size];
  for (int i = 1; i <= size; i++) a[i] = i;
  for (int i = 1; i <= size; i++) {
    if (a[i] && i > 1) {
      for (int j = 2 * i; j <= size; j += i) a[j] = 0;
      pr++;
    }
    if (ispalin(i)) pl++;
    if (q * pr <= p * pl) n = i;
  }
  if (n != -1)
    cout << n;
  else
    cout << "Palindromic tree is better than splay tree";
}
int ispalin(int n) {
  int r = n, count = 0;
  while (r) {
    count = (10 * count + r % 10);
    r /= 10;
  }
  if (n == count) return 1;
  return 0;
}
