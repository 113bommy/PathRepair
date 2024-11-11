#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, m, k;
  scanf("%d:%d", &h, &m);
  scanf("%d", &k);
  m += k;
  if (m >= 60) {
    h += (m / 60);
    m %= 60;
  }
  if (h >= 24) {
    h %= 24;
  }
  if (h < 10) {
    cout << '0';
  }
  cout << h << ":";
  if (m < 10) {
    cout << '0';
  }
  cout << m << endl;
}
