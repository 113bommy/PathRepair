#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  n--;
  long long i = 0;
  long long prev = 0;
  while (n >= 0) {
    i++;
    prev = n;
    n = n - i;
  }
  cout << prev + 1;
  return 0;
}
