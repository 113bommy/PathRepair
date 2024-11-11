#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, z = 0;
  cin >> n;
  char *colours = new char[50];
  for (int x = 0; x < n; x++) {
    cin >> colours[x];
  }
  for (int i = 0; i < n - 1; i++) {
    if (colours[i] == colours[i + 1]) {
      z++;
    }
  }
  delete[] colours;
  cout << z;
  return 0;
}
