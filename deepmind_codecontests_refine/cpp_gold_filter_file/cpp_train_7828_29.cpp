#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, max = 0, sum = 0;
  cin >> n;
  int mat[n];
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
    if (mat[i] > max) max = mat[i];
  }
  int set[max + 1];
  for (int i = 0; i <= max; i++) set[i] = 0;
  for (int i = 0; i < n; i++) set[mat[i]]++;
  for (int i = 0; i <= max; i++) sum = sum + set[i] / 2;
  cout << sum / 2 << endl;
  return 0;
}
