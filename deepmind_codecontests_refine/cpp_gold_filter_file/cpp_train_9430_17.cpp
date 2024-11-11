#include <bits/stdc++.h>
using namespace std;
char a[1005], b[1005], c[1005];
int main() {
  int sum = 0, i;
  cin.getline(a, 2000000000);
  cin.getline(b, 2000000000);
  cin.getline(c, 2000000000);
  for (i = 0; a[i] != '\0'; i++) {
    if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'u' ||
        a[i] == 'o') {
      sum++;
    }
  }
  if (sum != 5) {
    cout << "NO";
    return 0;
  }
  sum = 0;
  for (i = 0; b[i] != '\0'; i++) {
    if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'u' ||
        b[i] == 'o') {
      sum++;
    }
  }
  if (sum != 7) {
    cout << "NO";
    return 0;
  }
  sum = 0;
  for (i = 0; c[i] != '\0'; i++) {
    if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'u' ||
        c[i] == 'o') {
      sum++;
    }
  }
  if (sum != 5) {
    cout << "NO";
    return 0;
  }
  cout << "YES";
  return 0;
}
