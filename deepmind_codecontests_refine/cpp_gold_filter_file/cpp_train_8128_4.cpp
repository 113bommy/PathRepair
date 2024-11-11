#include <bits/stdc++.h>
using namespace std;
int a[25];
int poz[25];
void sorta() {
  for (int i = 0; i <= 24; i++)
    if (a[i] > a[i + 1]) {
      int temp;
      temp = a[i];
      a[i] = a[i + 1];
      a[i + 1] = temp;
      char temp1;
      temp1 = poz[i];
      poz[i] = poz[i + 1];
      poz[i + 1] = temp1;
      if (i != 0) i -= 2;
    }
}
int main() {
  char s[100000];
  int k, n;
  cin >> s >> k;
  n = strlen(s);
  for (int i = 0; i < n; i++) a[s[i] - 97]++;
  for (int i = 0; i <= 25; i++) poz[i] = i;
  for (int i = 0; i <= 25; i++)
    if (a[i] == 0) {
      a[i] = 100001;
    }
  sorta();
  int i = 0;
  while (k > 0) {
    if (k >= a[i]) {
      k -= a[i];
      a[i] = 100001;
      i++;
    } else
      break;
  }
  int nr = 0;
  for (int j = 0; j <= 25; j++)
    if (a[poz[j]] != 100001) nr++;
  cout << nr << "\n";
  for (int i = 0; i < n; i++) {
    int ok = 1;
    for (int j = 0; j <= 25 && ok != 3; j++) {
      if (a[j] != 100001 && ok == 1) ok = 2;
      if (a[j] == 100001 && ok == 2) ok = 3;
      if (((int)s[i] - 97) == poz[j] && a[j] != 100001) {
        cout << s[i];
        j = 40;
      }
    }
  }
  return 0;
}
