#include <bits/stdc++.h>
using namespace std;
const int MAX = 301;
int main() {
  int a, wallet[MAX];
  cin >> a;
mylabel:
  for (int i = 1; i <= a; i++) {
    cin >> wallet[i];
  }
  for (int i = 1; i < a; i++)
    if (wallet[i] != 0) {
      cout << 'P' << 'R';
      wallet[i]--;
    } else
      cout << 'R';
  for (int i = a; i > 1; i--)
    if (wallet[i] != 0) {
      cout << 'P' << 'L';
      wallet[i]--;
    } else
      cout << 'L';
  for (int i = a; i >= 0; i--)
    if (wallet[i] != 0) goto mylabel;
  return 0;
}
