#include <bits/stdc++.h>
using namespace std;
char c[6];
long n[6], n1[6];
int Abs(int a) {
  if (a < 0) {
    return -a;
  }
  return a;
}
bool cmp(int a, int b) { return a > b; }
int main() {
  cin >> c;
  for (int i = 0; i < 6; i++) {
    if (i <= 2) {
      n[i] = c[i] - '0';
      n1[i] = c[i] - '0';
      n1[i] = 9 - n1[i];
    } else {
      n1[i] = c[i] - '0';
      n[i] = c[i] - '0';
      n[i] = 9 - n1[i];
    }
  }
  int cha = n[0] + n[1] + n[2] - n1[3] - n1[4] - n1[5];
  sort(n, n + 6, cmp);
  sort(n1, n1 + 6, cmp);
  int cha1 = cha;
  int cnt, cnt1;
  if (cha > 0) {
    for (int i = 0; cha > 0 && i <= 5; i++) {
      cha -= n[i];
      cnt++;
    }
    cout << cnt << endl;
  } else {
    for (int i = 0; i <= 5 && cha1 < 0; i++) {
      cha1 += n1[i];
      cnt1++;
    }
    cout << cnt1 << endl;
  }
  return 0;
}
