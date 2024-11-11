#include <bits/stdc++.h>
using namespace std;
long long i, j, a;
int main() {
  cin >> a;
  j = 1;
  for (i = 1; i <= a; i++) {
    j *= 2;
    if (i == 13) j -= 100;
  }
  cout << j;
}
