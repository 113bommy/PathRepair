#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, i = 1, j = 1, m = 0, aa = 0, ba = 0;
  cin >> a >> b;
  while (1) {
    if (a * i > b * j) {
      ba = ba + (b * j - m);
      m = b * j;
      j++;
    } else if (a * i < b * j) {
      aa = aa + (a * i - m);
      m = a * i;
      i++;
    } else if (a * i == b * j) {
      if (b > a) {
        ba = ba + (b * j - m);
        m = b * j;
        j++;
      } else {
        aa = aa + (a * i - m);
        m = a * i;
        i++;
      }
      break;
    }
  }
  if (aa == ba) {
    cout << "Equal";
  } else if (aa < ba) {
    cout << "Masha";
  } else if (aa > ba) {
    cout << "Dasha";
  }
  return 0;
}
