#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int number_foto = 0;
  int max_like = 0;
  int a[1000001];
  cin >> n;
  int indef;
  for (int i = 1; i <= n; i++) {
    cin >> indef;
    a[indef]++;
    if (max_like < a[indef]) {
      max_like = a[indef];
      number_foto = indef;
    }
  }
  cout << number_foto;
  return 0;
}
