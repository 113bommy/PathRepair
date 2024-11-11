#include <bits/stdc++.h>
using namespace std;
int n, x, maxx = INT_MIN, A[3000], at, esek, keci;
char son, bas, orta;
map<char, int> mp, tp;
int main() {
  string a, b, c;
  cin >> a >> b >> c;
  if (a[1] == '<') {
    mp[a[2]]++;
  }
  if (a[1] == '>') {
    mp[a[0]]++;
  }
  if (b[1] == '<') {
    mp[b[2]]++;
  }
  if (b[1] == '>') {
    mp[b[0]]++;
  }
  if (c[1] == '<') {
    mp[c[2]]++;
  }
  if (c[1] == '>') {
    mp[c[0]]++;
  }
  for (char i = 'A'; i <= 'C'; i++) {
    if (mp[i] == 2) {
      at = 1;
      son = i;
    }
    if (mp[i] == 1) {
      esek = 2;
      orta = i;
    }
    if (mp[i] == 0) {
      keci = 3;
      bas = i;
    }
  }
  if (at != 1 || esek != 2 || keci != 3) {
    printf("Impossible");
    return 0;
  }
  printf("%c%c%c", bas, orta, son);
  return 0;
}
