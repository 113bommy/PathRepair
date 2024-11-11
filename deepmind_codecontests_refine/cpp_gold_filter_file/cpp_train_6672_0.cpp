#include <bits/stdc++.h>
using namespace std;
int isvowel(char ch) {
  if (ch == 'a' || ch == 'o' || ch == 'u' || ch == 'i' || ch == 'e')
    return 1;
  else
    return 0;
}
int isvalid(char ch) {
  if (ch == 'a' || ch == 'o' || ch == 'u' || ch == 'i' || ch == 'e' ||
      ch == 'n')
    return 1;
  else
    return 0;
}
int main() {
  long long int n, pa, pb, a, b, valid = 1, tb;
  cin >> n;
  cin >> pa >> pb;
  if (pa > pb) swap(pa, pb);
  for (int i = 1; i < n && valid == 1; i++) {
    cin >> a >> b;
    if (pb >= a && pb >= b)
      tb = max(a, b);
    else if (pb >= a && pb <= b)
      tb = a;
    else if (pb <= a && pb >= b)
      tb = b;
    else {
      valid = 0;
      break;
    }
    pb = tb;
  }
  if (valid == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
