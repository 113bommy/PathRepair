#include <bits/stdc++.h>
using namespace std;
int ps2max, usbmax, anymax;
long int sum, countbuy;
struct Goods {
  long long int p;
  int type;
} goods[400000];
bool u(char s[10]) { return s[0] == 'U' && s[1] == 'S' && s[2] == 'B'; }
bool ps(char s[10]) {
  return s[0] == 'P' && s[1] == 'S' && s[2] == '/' && s[3] == '2';
}
bool cmp(struct Goods n, struct Goods k) { return n.p < k.p; }
int main() {
  int n;
  char s[10];
  scanf("%d %d %d", &usbmax, &ps2max, &anymax);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lli", &goods[i].p);
    scanf("%s", s);
    if (u(s))
      goods[i].type = 1;
    else if (ps(s))
      goods[i].type = 2;
  }
  sort(goods, goods + n, cmp);
  int countusb = 0, countps2 = 0, countany = 0;
  for (int i = 0; i < n; i++) {
    if (goods[i].type == 1) {
      if (countusb < usbmax) {
        sum = sum + goods[i].p;
        countbuy++;
        countusb++;
      } else if (countany < anymax) {
        sum = sum + goods[i].p;
        countbuy++;
        countany++;
      }
    } else if (goods[i].type == 2) {
      if (countps2 < ps2max) {
        sum = sum + goods[i].p;
        countbuy++;
        countps2++;
      } else if (countany < anymax) {
        sum = sum + goods[i].p;
        countbuy++;
        countany++;
      }
    }
  }
  printf("%ld %ld", countbuy, sum);
}
