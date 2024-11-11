#include <bits/stdc++.h>
using namespace std;
int n;
string st;
bool benar;
int main() {
  scanf("%d", &n);
  benar = false;
  st = "";
  while (n >= 0) {
    if (n % 4 == 0) {
      benar = true;
      break;
    }
    n -= 7;
    st = '7' + st;
  }
  if (benar) {
    while (n >= 28) {
      n -= 28;
      st = "7777" + st;
    }
    for (int i = 0; i < n / 4; i++) st = '4' + st;
    cout << st << endl;
  } else
    printf("-1\n");
}
