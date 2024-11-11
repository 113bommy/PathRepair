#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l = 0, r = 0;
  cin >> n;
  char dizi[n];
  for (int i = 0; i < n; i++) {
    cin >> dizi[i];
    if (dizi[i] == 'L') {
      l++;
    } else if (dizi[i] == 'R') {
      r++;
    }
  }
  cout << r + l + 1;
}
