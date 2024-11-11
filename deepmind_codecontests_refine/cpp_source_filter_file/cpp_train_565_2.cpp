#include <bits/stdc++.h>
using namespace std;
char s[3000];
int n, h, swa = 0, maxswap = 5000, i;
int main() {
  cin >> n;
  cin.getline(s, 3);
  cin.getline(s, 10005);
  for (i = 0; s[i]; i++)
    if (s[i] == 'H') h++;
  strcpy(s, s);
  for (i = 0; i < h; i++)
    if (s[i] == 'T') swa++;
  maxswap = swa;
  for (i = h; s[i]; i++) {
    if (s[i - h] == 'H' && s[h] == 'T')
      swa++;
    else if (s[i - h] == 'T' && s[h] == 'H')
      swa--;
    if (swa < maxswap) maxswap = swa;
  }
  swa = 0;
  h = n - h;
  for (i = 0; i < h; i++)
    if (s[i] == 'H') swa++;
  if (swa < maxswap) maxswap = swa;
  for (i = h; s[i]; i++) {
    if (s[i - h] == 'T' && s[h] == 'H')
      swa++;
    else if (s[i - h] == 'H' && s[h] == 'T')
      swa--;
    if (swa < maxswap) maxswap = swa;
  }
  cout << maxswap;
  return 0;
}
