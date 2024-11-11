#include <bits/stdc++.h>
using namespace std;
int mas[100100];
int col[100100];
int main() {
  int n, mx = 0, t, nmax = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> mas[i];
    col[mas[i]]++;
    if (mas[i] > mx) mx = mas[i];
  }
  for (int i = 1; i < mx; i++) {
    if (col[i] > nmax) nmax = col[i];
    if (col[i] < col[i + 1]) {
      cout << "-1";
      return 0;
    }
  }
  cout << nmax << endl;
  for (int i = 0; i < n; i++) {
    cout << col[mas[i]] << " ";
    col[mas[i]]--;
  }
  return 0;
}
