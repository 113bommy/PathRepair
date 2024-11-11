#include <bits/stdc++.h>
using namespace std;
int cnt, x, y, bI[200007];
string a, b;
int main() {
  cin >> a >> b;
  x = a.length(), y = b.length();
  for (int i = 0; i <= y - x; i++) bI[0] += b[i] == '1';
  for (int i = 1; i < x; i++)
    bI[i] = bI[i - 1] + (b[i + y - x] == '1') - (b[i - 1] == '1');
  for (int i = 0; i < x; i++) {
    cnt += (a[i] == '0') ? bI[i] : y - x - bI[i] + 1;
  }
  cout << cnt;
  return 0;
}
