#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char stone[n];
  int a = 0;
  for (int x = 0; x < n; x++) {
    cin >> stone[x];
  }
  for (int b = 0; b < n - 1; b++) {
    if (stone[b] == stone[b + 1]) {
      a++;
    }
  }
  cout << a;
  return 0;
}
