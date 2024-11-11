#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;
char a[600000], b[600000];
void kmp(int cnt) {
  int i = 0;
  int k = -1;
  b[0] = -1;
  while (i < cnt) {
    if (k == -1 || a[i] == a[k]) {
      if (a[++i] == a[++k])
        b[i] = b[k];
      else
        b[i] = k;
    } else
      k = b[k];
  }
  return;
}
int main() {
  char x;
  int a0 = 0, a1 = 0;
  while (scanf("%c", &x) && x != '\n') {
    if (x == '0')
      a0++;
    else
      a1++;
  }
  int k = 0;
  while (scanf("%c", &x) && x != '\n') a[k++] = x;
  kmp(k);
  int l = k - b[k];
  int s = 0;
  while (1) {
    if (s) break;
    for (int i = 0; i < l; i++) {
      if (a[i] == '0' && a0)
        printf("0"), a0--;
      else if (a[i] == '1' && a1)
        printf("1"), a1--;
      else {
        s = 1;
        break;
      }
    }
  }
  if (a0) {
    for (int i = 0; i < a0; i++) printf("0");
    cout << endl;
  } else if (a1) {
    for (int i = 0; i < a1; i++) printf("1");
    cout << endl;
  } else
    cout << endl;
  return 0;
}
