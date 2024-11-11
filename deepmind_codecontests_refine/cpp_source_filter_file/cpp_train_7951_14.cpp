#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      float c = sqrt(i * i + j * j);
      if (c - (int)c == 0 && c <= n) count++;
    }
  }
  cout << count;
  return 0;
}
