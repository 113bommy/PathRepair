#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const long long mod = 1000000;
const int prime = 999983;
const int INF = 0x3f3f3f3f;
const int INFF = 1e9;
const double pi = 3.141592653589793;
const double inf = 1e18;
const double eps = 1e-10;
inline int read_int() {
  int ret = 0;
  char tmp;
  while (!isdigit(tmp = getchar()))
    ;
  do {
    ret = (ret << 3) + (ret << 1) + tmp - '0';
  } while (isdigit(tmp = getchar()));
  return ret;
}
int d[(1 << 18)];
char str[100];
int get_data() {
  int shu = 0;
  int bin = 1;
  int len = strlen(str);
  for (int j = len - 1; j >= 0; j--) {
    int data = str[j] - '0';
    if (data & 1) shu += bin;
    bin *= 2;
  }
  return shu;
}
int main() {
  int n;
  cin >> n;
  char ord[10];
  int tmp;
  for (int i = 0; i < n; i++) {
    scanf("%s", ord);
    scanf("%s", str);
    if (ord[0] == '+') {
      d[get_data()]++;
    } else if (ord[0] == '-') {
      d[get_data()]--;
    } else
      printf("%d\n", d[get_data()]);
  }
}
