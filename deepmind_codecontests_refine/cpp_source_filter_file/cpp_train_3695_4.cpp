#include <bits/stdc++.h>
using namespace std;
int minimum(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  long long n, c = 0, k = 0;
  cin >> n;
  char a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == '1')
      c++;
    else
      k++;
  }
  cout << (n - minimum(c, k));
}
