#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, v;
  cin >> n >> v;
  int c = v, i = 1;
  while (i != n) {
    i++;
    if (n - i >= v) {
      c += i;
    }
  }
  if (n <= v) {
    c = n - 1;
  }
  cout << c;
}
