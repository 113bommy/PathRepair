#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int al, ar, bl, br;
  cin >> al >> ar >> bl >> br;
  int ans = 0;
  if (al >= br) {
    long long int dif = al - br;
    if (dif <= 1) ans = 1;
  } else {
    long long int dif = br - al;
    dif--;
    if (dif <= 2)
      ans = 1;
    else {
      if (dif <= (al + 1)) ans = 1;
    }
  }
  if (ar >= bl) {
    long long int dif = ar - bl;
    if (dif <= 1) ans = 1;
  } else {
    long long int dif = bl - ar;
    dif--;
    if (dif <= 2)
      ans = 1;
    else {
      if (dif <= ar + 1) ans = 1;
    }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
