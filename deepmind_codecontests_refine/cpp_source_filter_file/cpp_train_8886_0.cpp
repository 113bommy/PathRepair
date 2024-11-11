#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, z = 0;
  cin >> n;
  char *colours = new char[n];
  for (int x = 0; x < n; x++) {
    cin >> colours[x];
  }
  for (int i = 0; i < n; i++) {
    if (colours[i] == colours[i + 1]) {
      z++;
    }
  }
  delete[] colours;
  cout << z;
  return 0;
}
