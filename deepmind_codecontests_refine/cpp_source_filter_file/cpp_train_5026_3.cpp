#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
void solves() {
  int a[4];
  ;
  for (int i = 0; i < 4; i++) cin >> a[i];
  bool neg;
  if ((a[0] + a[1] % 2) == 0)
    neg = 0;
  else
    neg = 1;
  bool big;
  if ((a[0] + a[3]) != 0)
    big = 1;
  else
    big = 0;
  if (neg and big)
    cout << "Ya ";
  else
    cout << "Tidak ";
  if (neg and (a[1] != 0 or a[2] != 0))
    cout << "Ya ";
  else
    cout << "Tidak ";
  if (!neg and (a[1] != 0 or a[2] != 0))
    cout << "Ya ";
  else
    cout << "Tidak ";
  if (!neg and big)
    cout << "Ya ";
  else
    cout << "Tidak ";
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    solves();
  }
}
