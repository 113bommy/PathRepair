#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i = 2;
  cin >> n;
  int sum = n;
  while (n > 1) {
    sum += ((n - 2) * i) + 1;
    i++;
    n--;
  }
  cout << sum + 1;
}
